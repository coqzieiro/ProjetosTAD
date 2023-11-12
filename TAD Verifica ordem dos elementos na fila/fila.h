#ifndef FILA_H
	#define FILA_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>

	#define TAM_FILA 10

	typedef struct fila fila_t;

	fila_t *criar_fila();
	bool inserir(fila_t *f, int x);
	bool remover(fila_t *f, int *x);
	bool esta_vazia(fila_t *f);
	bool esta_cheia(fila_t *f);
	int tamanho(fila_t *f);
	void destruir_fila(fila_t *f);
#endif