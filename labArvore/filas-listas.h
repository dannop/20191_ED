#include "lista-encadeada.h"

typedef struct fila {
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *inicializa_fila(void);
int fila_vazia(TFila *f);
void insere_fila(TFila *f, int elem);
int retira_fila(TFila *f);
void libera_fila(TFila *f);
void imprime_fila(TFila *f);

