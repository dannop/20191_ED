#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    int chave;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void);
void imprime_arvore(TNoA *nodo, int tab);
TNoA *criaNo(int x);
int contaNos(TNoA *raiz); 
int contaNiveis(TNoA *raiz);
int nivel(TNoA *raiz, int x);  