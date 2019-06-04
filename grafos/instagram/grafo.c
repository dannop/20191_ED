#include "grafo.h"

TGrafo *insere_vertice(TGrafo *g, char *nome, int idade) {
    TGrafo *vertice = (TGrafo *) malloc(sizeof(TGrafo));
    strcpy(vertice->nome, nome);
    vertice->idade = idade;
    vertice->prox = g;
    vertice->vizinho = NULL;
    return vertice;
}

TGrafo *busca_vertice(TGrafo *vertice, char *nome) {
    while ((vertice != NULL) && (strcmp(vertice->nome, nome) != 0)) {
        vertice = vertice->prox;
    }
    return vertice;
}

TVizinho *busca_vizinho(TVizinho *vizinho, char *nome) {
    while ((vizinho != NULL) && (strcmp(vizinho->nome, nome) != 0)) {
        vizinho = vizinho->prox;
    }
    return vizinho;
}

void insere_aresta(TGrafo *g, char *nome_origem, char *nome_destino) {
    TGrafo *vertice = busca_vertice(g, nome_origem);
    TVizinho *vizinho = (TVizinho *) malloc(sizeof(TVizinho));
    strcpy(vizinho->nome, nome_destino);
    vizinho->prox = vertice->vizinho;
    vertice->vizinho = vizinho;
}

void imprime(TGrafo *vertice) {
    while (vertice != NULL) {
        printf("Pessoa: %s - %d anos\n", vertice->nome, vertice->idade);
        printf("Segue: ");
        TVizinho *vizinho = vertice->vizinho;
        while (vizinho != NULL) {
            printf("%s ", vizinho->nome);
            vizinho = vizinho->prox;
        }
        printf("\n\n");
        vertice = vertice->prox;
    }
}

int numero_seguidos(TGrafo *g, char *nome) {
    //Auxiliar que percorre o grafo "principal"
    TGrafo *aux;
    //Retorna o grafo principal.
    aux = busca_vertice(g, nome);
    //Tipo vizinho que recebe o primeiro vizinho;
    TVizinho *aux_zinho;
    aux_zinho = aux->vizinho;
    int cont = 0;
    
    while (aux_zinho!=NULL){
    	++cont;
    	aux_zinho = aux_zinho->prox;
    }
    return cont;
}

int seguidores(TGrafo *vertice, char *nome, int imprime) {
    TGrafo *aux;
    aux = vertice;
    int cont = 0;
    while (aux != NULL){
    	TVizinho *aux_zinho = aux->vizinho;
    	aux_zinho = busca_vizinho(aux_zinho, nome);
    	if (aux_zinho!=NULL){
    		++cont;
    		if(cont == 1 && imprime == 1) printf("Os seguidores de %s are: \n", nome);
    		
    		if (imprime == 1) printf("%s\n", aux->nome);
    	}
    	aux = aux->prox;	
    }

    return cont;
}

TGrafo *mais_popular(TGrafo *g) {
    int atual;
    int maior = 0;
    TGrafo *gMaior = g;
    while (g != NULL){
    	atual = seguidores (g, g->nome, 0);

    	if (atual > maior) {
    		maior = atual;
    		gMaior = g;
    	}
    	g = g->prox;    		
    }
    return gMaior;
}

int segue_mais_velho(TGrafo *g, int imprime) {
    
    TGrafo *percorreGrafo = g;  //Auxiliar para percorrer o grafo.
    int contador = 0; //retorna o número de pessoas que seguem os mais velhos.
    while (percorreGrafo !=NULL){
    	
    	int total=0; //total de seguidores do grafo atual.
    	int idade = percorreGrafo->idade; //idade do grafo atual.
    	int maisvelhos=0; //número de mais velhos.
    	
    	TVizinho *percorreVizinho = percorreGrafo->vizinho; //Resoler o problema da busca no vértice. (Precisa ser TVizinho)
    	
    	while (percorreVizinho !=NULL){
    		
    		TGrafo *percorreGrafoAux = g; //Auxiliar que faz a busca pelo vertice do vizinho atual, para pegar a idade.

    		percorreGrafoAux = busca_vertice(percorreGrafoAux, percorreVizinho->nome); 		
 		
    		if (idade < percorreGrafoAux->idade){ 
    			++maisvelhos;
    		}

    		++total; 
    		percorreVizinho = percorreVizinho->prox;
    		
    	}

    	//printf("%s, de %d anos, tem o total de %d, seguidores e segue %d pessoas mais velhas que ele (a).\n", percorreGrafo->nome, idade, total, maisvelhos);
    	if (total == maisvelhos && maisvelhos != 0 && imprime == 1){
            printf("%s ", percorreGrafo->nome);    
            ++contador;
        }   	
    
        percorreGrafo=percorreGrafo->prox;	
    }

    printf("\n");
    return contador;
    
}

void libera_vizinho(TVizinho *vizinho) {
    if (vizinho != NULL) {
        libera_vizinho(vizinho->prox);
        free(vizinho);
    }
}

void libera_vertice(TGrafo *vertice) {
    if (vertice != NULL) {
        libera_vizinho(vertice->vizinho);
        libera_vertice(vertice->prox);
        free(vertice);
    }
}

int main() {
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