#ifndef FILA_H
	#define FILA_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>

	#define TAM_FILA 10  // define o tamanho maximo da fila

	typedef struct fila fila_t;  // define um tipo fila_t como um alias para struct fila

	fila_t *criar_fila();  // declara uma funcao para criar uma nova fila
	bool inserir(fila_t *f, void *x);  // declara uma funcao para inserir um elemento na fila
	bool remover(fila_t *f, void **x);  // declara uma funcao para remover um elemento da fila
	bool esta_vazia(fila_t *f);  // declara uma funcao para verificar se a fila esta vazia
	bool esta_cheia(fila_t *f);  // declara uma funcao para verificar se a fila esta cheia
	int tamanho(fila_t *f);  // declara uma funcao para obter o tamanho da fila
	void destruir_fila(fila_t *f);  // declara uma funcao para destruir a fila e liberar a memoria alocada

#endif