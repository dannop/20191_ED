#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    }
    else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}


TNoA *exclui(TNoA *raiz, int chave){
    //buscando o valor
    
    if (raiz == NULL) return NULL;
    else if (raiz->chave > chave) raiz->esq = exclui(raiz->esq, chave);
    else if (raiz->chave < chave) raiz->dir = exclui(raiz->dir, chave);
    //Se o valor for achado vai cair nesse caso:
    else if (raiz->chave == chave){
        //Primeiro Caso: Excluindo um no sem filhos
        if (raiz->dir == NULL && raiz->esq == NULL) {
            
            free (raiz);
            return raiz;
        }
        //Segundo Caso: Excluindo um nó que tem um filho que fica à direita.
        else if (raiz->dir !=NULL && raiz->esq == NULL){
            TNoA *aux = raiz;
            //A raiz aponta para o próximo
            raiz = raiz->dir;
            free (aux);
        }

        //Terceiro Caso: Excluindo um nó que tem um filho que fica a esquerda.
        else if (raiz->dir ==NULL && raiz->esq != NULL){
            TNoA *aux = raiz;
            //A raiz aponta para o próximo
            raiz = raiz->esq;
            free (aux);
        }
        //Quarto Caso: Excluindo um nó que tem um filho de cada lado.
        else if (raiz->dir != NULL && raiz->esq !=NULL){
            TNoA *atual = raiz;
            TNoA *percorre = raiz->esq;
            //buscando o maior:
            while (percorre->dir!=NULL) (percorre = percorre->dir);
            //trocar:
            raiz->chave = percorre->chave;
            percorre->chave = atual->chave;
            raiz->esq = exclui (raiz->esq, chave); //resolvendo recursivamente


        }


    return raiz;
        
        
        
    }
}

int main(void) {
    TNoA *raiz;
    raiz = NULL;
    //arvore usada no slide da disciplina
    raiz = insere(raiz, 200);
    //subarvore esquerda
    insere(raiz, 100);
    insere(raiz, 80);
    insere(raiz, 150);
    insere(raiz, 70);
    insere(raiz, 65);
    insere(raiz, 79);
    insere(raiz, 120);
    insere(raiz, 110);
    insere(raiz, 130);

    //subarvore direita
    insere(raiz, 300);
    insere(raiz, 250);
    insere(raiz, 400);
    insere(raiz, 220);
    insere(raiz, 270);
    insere(raiz, 260);
    insere(raiz, 350);
    insere(raiz, 500);

    imprime(raiz, 0);

    exclui(raiz, 260);
    exclui(raiz, 150);
    exclui(raiz, 80);
    exclui(raiz, 270);
    exclui(raiz, 400);
    exclui(raiz, 200);
    
    printf("\n\nArvore resultante da exclusão: \n");
    imprime (raiz, 0);
    };