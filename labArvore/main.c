#include <stdio.h>
#include "filas-listas.h"
#include "arvore-binaria.h"
    
/*
 * Retorna fila com ancestrais do nó x. Caso x não exista na árvore, retorna fila vazia.
 */
TFila *ancestrais(TNoA *raiz, int x) {

    if (raiz == NULL) return NULL;
    
    else if (raiz->chave == x){
        TFila *aux = inicializa_fila();
        insere_fila (aux, raiz->chave);
        return aux;
    } 
       
    else {

        TFila *aux = inicializa_fila();

        if (x < raiz->chave && raiz->esq !=NULL) aux  = ancestrais(raiz->esq, x); 
        
        if (x > raiz->chave && raiz->dir !=NULL) aux  = ancestrais(raiz->dir, x);

        if (!fila_vazia(aux)) insere_fila(aux, raiz->chave);

        return aux; 
    }
     
}

int main() {
    TNoA *raiz;
    int soma;
    raiz = criaNo(50);
    raiz->esq = criaNo(25);
    raiz->dir = criaNo(70);
    raiz->dir->esq = criaNo(60);
    raiz->dir->dir = criaNo(80);
    raiz->dir->dir->dir = criaNo(100);
    imprime_arvore(raiz, 0);
    printf("\nAncestrais de 70:\n");
    imprime_fila(ancestrais(raiz, 70));
    printf("\nAncestrais de 100:\n");
    imprime_fila(ancestrais(raiz, 100));
    printf("\nAncestrais de 20:\n");
    imprime_fila(ancestrais(raiz, 20));
}