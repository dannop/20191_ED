#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct vizinho {
    char nome[10];
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    char nome[10];
    int idade;
    TVizinho *vizinho;
    struct grafo *prox;
} TGrafo;


//Implementacao inicial
TGrafo *busca_vertice(TGrafo *vertice, char *nome);
TGrafo *insere_vertice(TGrafo *g, char *nome, int idade);
TVizinho *busca_vizinho(TVizinho *vizinho, char *nome);
void insere_aresta(TGrafo *g, char *nome_origem, char *nome_destino);
void libera_vizinho(TVizinho *vizinho);
void libera_vertice(TGrafo *vertice);
void imprime(TGrafo *vertice);

//Implementacao avancada
TGrafo *mais_popular(TGrafo *g);
int numero_seguidos(TGrafo *g, char *nome);
int seguidores(TGrafo *vertice, char *nome, int imprime);
int segue_mais_velho(TGrafo *g, int imprime);
int testeK(TGrafo *g, int k);