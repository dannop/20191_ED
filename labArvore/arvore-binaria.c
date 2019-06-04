#include "arvore-binaria.h"

TNoA *inicializa(void) {
    return NULL;
}

void imprime_arvore(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime_arvore(nodo->esq, tab + 2);
        printf("\n");
        imprime_arvore(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(int x) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int contaNos(TNoA *raiz){
	if (raiz == NULL) return 0;
	else return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);

 }

 int contaNiveis(TNoA *raiz){
	if (raiz == NULL) return -1;
	else{
		int niveld = contaNiveis (raiz->dir);
		int nivele = contaNiveis (raiz->esq);
		if (niveld > nivele) return ++niveld;
			else return ++nivele;
	}

}

int nivel(TNoA *raiz, int x){
	if (raiz == NULL || raiz->chave == x) return 0;
	if (x < raiz->chave)  return 1 + nivel(raiz->esq, x);
	else return 1 + nivel(raiz->dir, x); 
} 
