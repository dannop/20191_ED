#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdarg.h>

#include "lista_nos_internos.h"


void imprime_nos_internos(int d, TListaNosInternos *lc)
{
	int i;
	for (i = 0; i < lc->qtd; i++) {
		imprime_no_interno(d, lc->lista[i]);
	}
}

TListaNosInternos *cria_nos_internos(int d, int qtd, ...)
{
	va_list ap;
	TListaNosInternos *lc = (TListaNosInternos *)  malloc(sizeof(TListaNosInternos));
	lc->qtd = qtd;
	lc->lista = (TNoInterno **) malloc(sizeof(TNoInterno *) * (qtd));
	int i;
	va_start(ap, qtd);
	for (i = 0; i < qtd; i++) {
        lc->lista[i] = va_arg(ap, TNoInterno *);
    }
    va_end(ap);
    return lc;
}

void salva_nos_internos(int d, char *nome_arquivo, TListaNosInternos *lc)
{
	FILE *out = fopen(nome_arquivo, "wb");
	int i;
	for (i = 0; i < lc->qtd; i++) {
		salva_no_interno(d, lc->lista[i], out);
	}
	fclose(out);
}

TListaNosInternos * le_nos_internos(int d, char *nome_arquivo)
{
	int qtd = 0;
	TListaNosInternos *lc = (TListaNosInternos *)  malloc(sizeof(TListaNosInternos));
	FILE *in = fopen(nome_arquivo, "rb");
	if (in != NULL) {
		TNoInterno *no = NULL;
		while((no = le_no_interno(d, in)) != NULL) {
			qtd += 1;
			libera_no_interno(no);
		}
		fseek(in, 0, SEEK_SET);
		lc->qtd = qtd;
		lc->lista = (TNoInterno **) malloc(sizeof(TNoInterno *) * (qtd));
		qtd = 0;
		while((no = le_no_interno(d, in)) != NULL) {
			lc->lista[qtd++] = no;
		}
		fclose(in);
	} else {
		lc->qtd = 0;
		lc->lista = NULL;
	}
	return lc;
}

int cmp_nos_internos(int d, TListaNosInternos *c1, TListaNosInternos *c2)
{
	if (c1->qtd != c2->qtd) {
		return 0;
	}
	int i;
	for (i = 0; i < c1->qtd; i++) {
		if (!cmp_no_interno(d, c1->lista[i], c2->lista[i])) {
			return 0;
		}
	}
	return 1;
}

void libera_nos_internos(TListaNosInternos *lc)
{
	int i;
	for (i = 0; i < lc->qtd; i++) {
		libera_no_interno(lc->lista[i]);
	}
	free(lc->lista);
	free(lc);
}
