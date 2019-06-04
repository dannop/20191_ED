#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "arvore-binaria.h"


int main(){
    TGrafo *p;
    TGrafo *g = NULL;
    g = insere_vertice(g, "Joao", 25);
    g = insere_vertice(g, "Ana", 23);
    g = insere_vertice(g, "Caio", 20);
    g = insere_vertice(g, "Pedro", 20);
    g = insere_vertice(g, "Jane", 30);
    g = insere_vertice(g, "Marcos", 19);
    g = insere_vertice(g, "Bruna", 23);
    g = insere_vertice(g, "Felipe", 20);
    g = insere_vertice(g, "Renata", 35);

    insere_aresta(g, "Ana", "Joao");
    insere_aresta(g, "Ana", "Jane");

    insere_aresta(g, "Joao", "Ana");
    insere_aresta(g, "Joao", "Pedro");
    insere_aresta(g, "Joao", "Caio");

    insere_aresta(g, "Pedro", "Caio");
    insere_aresta(g, "Pedro", "Jane");
    insere_aresta(g, "Pedro", "Bruna");
    insere_aresta(g, "Pedro", "Marcos");

    insere_aresta(g, "Jane", "Pedro");
    insere_aresta(g, "Jane", "Marcos");
    insere_aresta(g, "Jane", "Bruna");

    insere_aresta(g, "Marcos", "Felipe");
    insere_aresta(g, "Marcos", "Renata");

    insere_aresta(g, "Bruna", "Renata");

    insere_aresta(g, "Felipe", "Renata");
    insere_aresta(g, "Felipe", "Marcos");

    imprime(g);

    //Encontra o número de seguidos de Pedro
    printf("Número de pessoas que Caio Segue: %d\n", numero_seguidos(g, "Caio"));

    //Encontra os seguidores de uma determinada pessoa
    seguidores(g, "Jane", 1);

    //Encontra mais popular
    p = mais_popular(g);

    if (p != NULL) {
        printf("Mais popular: %s\n", p->nome);
    }

    //Encontra as pessoas que seguem apenas pessoas da mesma idade

    segue_mais_velho(g, 1);

    libera_vertice(g);
}