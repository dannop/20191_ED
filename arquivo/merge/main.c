#include <stdio.h>
#include <stdlib.h>

void merge(char* nomeArq1, char* nomeArq2, char* nomeArqMerge){
    FILE *arq1, *arq2, *arq_merge; 
    
    arq1 = fopen(nomeArq1, "r");
    arq2 = fopen(nomeArq2, "r");
    arq_merge = fopen(nomeArqMerge, "w");

    if (arq1 != NULL && arq2 != NULL && arq_merge != NULL){
        int i, j = 0;

        fscanf(arq1, "%d", &i);
        fscanf(arq2, "%d", &j);

        while (!feof(arq1) && !feof(arq2)) {
            if (i < j) {
                fprintf(arq_merge, "%d\n", i);
                fscanf(arq1, "%d", &i);
            } else {
                if ( i > j) {
                    fprintf(arq_merge, "%d\n", j);
                    fscanf(arq2, "%d", &j);
                } else {
                    fprintf(arq_merge, "%d\n", i);
                    //fprintf(arq_merge, "%d\n", j);
                    fscanf(arq1, "%d", &i);
                    fscanf(arq2, "%d", &j);
                }
            }
            
        }

        while (!feof(arq1)) {
            fprintf(arq_merge, "%d\n", i);
            fscanf(arq1, "%d", &i);
        }

        while (!feof(arq2)) {
            fprintf(arq_merge, "%d\n", j);
            fscanf(arq2, "%d", &j);
        }
    } else printf("Erro ao abrir os arquivos.\n");

    fclose(arq1);
    fclose(arq2);
    fclose(arq_merge);
}

int main(){
    merge("numeros1.txt", "numeros2.txt", "resultado.txt");
}