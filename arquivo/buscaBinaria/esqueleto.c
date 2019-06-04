#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Funcionario {
    int cod;
    char nome[50];
    double salario;
} TFunc;

// Imprime funcionario
void imprime(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de código ");
    printf("%d", func->cod);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nSalário: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}

/*
 * Cria funcionario
 */
TFunc *funcionario(int cod, char *nome, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    //inicializa espaço de memória com ZEROS
    if (func) memset(func, 0, sizeof(TFunc));
    //copia valores para os campos de func
    func->cod = cod;
    strcpy(func->nome, nome);
    func->salario = salario;
    return func;
}

/*
 * Salva funcionario no arquivo out, na posicao atual do cursor
 */
void salva(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    //func->nome ao invés de &func->nome, pois string já é ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(&func->salario, sizeof(double), 1, out);
}


int tamanho_arquivo(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    int tam = trunc(ftell(arq) / tamanho_registro());
    return tam;
}

/*
 * Retorna tamanho do registro de funcionario em bytes
 */
int tamanho_registro() {
    return sizeof(int)  //cod
           + sizeof(char) * 50 //nome
           + sizeof(double); //salario
}

/*
 * Insere funcionários no arquivo e
 */
void insere_funcionarios(FILE *out) {
    TFunc *f;
    f = funcionario(102, "Joao Silva", 1000);
    salva(f, out);
    f = funcionario(123, "Carlos Albuquerque", 1500);
    salva(f, out);
    f = funcionario(143, "Ana Bueno", 1500);
    salva(f, out);
    f = funcionario(200, "Caio Gusmão", 4000);
    salva(f, out);
    f = funcionario(239, "Bianca Amarilo", 3000);
    salva(f, out);
    f = funcionario(254, "Arnaldo Souza", 4300);
    salva(f, out);
    f = funcionario(305, "Marisa Clara", 5000);
    salva(f, out);
    f = funcionario(403, "Bruno Simão", 4500);
    salva(f, out);
    f = funcionario(410, "Guilherme Santos", 2000);
    salva(f, out);
    f = funcionario(502, "Tatiana Andrade", 2500);
    salva(f, out);
    free(f);
}

TFunc *carrega(FILE *in) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    
    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }
    
    fread(&func->cod, sizeof(int), 1, in);
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}

/*
 * Implementa busca binária em arquivo binário
 * cod é a chave do funcionário a ser buscada
 * nome_arquivo é o nome do arquivo que contém os funcionários
 * tam é a quantidade de registros que o arquivo contém
 */
TFunc *busca_binaria(int cod, FILE *arq, int tam) {
    TFunc *f = NULL;
    int inicio = 1;
    int fim = tam;
    int meio = trunc((inicio + fim) / 2);
    
    fseek(arq, tamanho_registro() * (meio-1), SEEK_SET);
    f = carrega(arq);

    //Arquivo com 1 registro e diferente do desejado
    if (meio <= 1 && f->cod != cod) return NULL;

    while (inicio <= fim) {
        if (f->cod == cod) return f;
        else if (f->cod > cod) fim = meio-1;
        else inicio = meio+1;

        meio = trunc((inicio + fim)/2);
        fseek(arq, tamanho_registro() * (meio-1) , SEEK_SET);
        f = carrega(arq);
    }

    return f;
}

int main() {
    //declara ponteiro para arquivo
    FILE *arq;
    //abre arquivo para leitura e escrita
    if ((arq = fopen("funcionario.dat", "wb+")) == NULL) {
        printf("Erro ao abrir arquivo\n");
    } else {
        //insere funcionários
        insere_funcionarios(arq);
        //força flush para salvar funcionários
        fflush(arq);
        TFunc *f = busca_binaria(305, arq, tamanho_arquivo(arq));
        if (f != NULL) {
            imprime(f);
            free(f);
        }
        fclose(arq);
    }
}