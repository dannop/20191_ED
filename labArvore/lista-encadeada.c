#include "lista-encadeada.h"

TLista* cria_lista (void) {
    return NULL;
}

TLista* insere_inicio (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) { /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}

TLista* insere_ordenado (TLista* li, int i) {
    TLista* novo;
    TLista* ant = NULL; /* ponteiro para elemento anterior */
    TLista* p = li; /* ponteiro para percorrer a lista */
    /* procura posição de inserção */
    while (p != NULL && p->info < i) {
        ant = p;
        p = p->prox;
    }
    /* cria novo elemento */
    novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    /* encadeia elemento */
    if (ant == NULL) { /* insere elemento no início */
        novo->prox = li; li = novo;
    }
    else { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return li;
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}


