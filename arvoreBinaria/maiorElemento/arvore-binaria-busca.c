#include "arvore-binaria.h"

//Tentativa Falha.

typedef struct lista {
    char info;
    struct lista* prox;
} TLista;

typedef struct pilha{
    TLista *topo;
} TPilha;

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio\n");
}

TNoA *criaNo(int ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TPilha *criaPilha(){
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

int pilha_vazia(TPilha *pilha) {
    return (pilha->topo == NULL);
}

void push(TPilha *pilha, TNoA* no) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = no->info;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

char pop(TPilha *pilha) {
    if (pilha_vazia(pilha)) exit (1);
    
    else {
        TLista *p = pilha->topo;    
        pilha->topo = pilha->topo->prox;
        free (p);
        return pilha->topo->info;
    }
}

char peek(TPilha *pilha) {
    if (pilha_vazia(pilha)) exit(1);
    return pilha->topo->info;
}

void imprimirPosOrdemIterativo(TNoA *raiz){
    if (raiz == NULL) return;

    TPilha *p = criaPilha(); 
 
    do {
        while (raiz) { 
            if (raiz->dir) push(p, raiz->dir);
            push(p, raiz);
            raiz = raiz->esq;
        }

        raiz->info = pop(p);

        if (raiz->dir && peek(p) == raiz->dir->info){
            pop(p);
            push(p, raiz);
            raiz = raiz->dir;
        } else {
            printf("%c ", raiz->info);
            raiz = NULL;
        }
    }while (!pilha_vazia(p));
}

TNoA* maior(TNoA *a){
    //A árvore binária está ordenada.
    if (a->dir == NULL) return a;
    else maior (a->dir);


}


int main(void) {
    TNoA *raiz;
    
    raiz = criaNo(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(1);
    raiz->dir->esq = criaNo(1);
    raiz->dir->dir = criaNo(5);
    imprime(raiz, 0);
    TNoA *b = inicializa(); 
    b = maior(raiz);
    printf("%d\n", b->info);
}   