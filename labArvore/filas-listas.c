#include "filas-listas.h"

TFila *inicializa_fila(void){
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(TFila *f){
    if (f->inicio == NULL) {
        return 1;
    }
    else return 0;
}

void insere_fila(TFila *f, int elem){
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; //inserção no fim da fila
    if (!fila_vazia(f)){
        f->fim->prox = novo;
    }
    else{
        f->inicio = novo;
    }
    f->fim = novo; //elemento inserido é o novo fim da fila
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira_fila(TFila *f){
    if (fila_vazia(f)){
        exit(1);
    }
    int info = f->inicio->info;

    TLista *aux = f->inicio;
    f->inicio=f->inicio->prox;
    //se elemento removido era o único da fila
    //faz fim apontar para NULL também
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void libera_fila(TFila *f){
    TLista *q, *p = f->inicio;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(f);
}

void imprime_fila(TFila *f){
    TFila *aux = inicializa_fila();
    while(!fila_vazia(f)){
        int x = retira_fila(f);
        printf("%d ", x);
        insere_fila(aux, x);
    }
    while(!fila_vazia(aux)){
        insere_fila(f, retira_fila(aux));
    }
    libera_fila(aux);
}

