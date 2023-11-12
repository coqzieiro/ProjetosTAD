#include "fila.h"

struct fila {
	int inicio, fim, total;
	int itens[TAM_FILA];
};

fila_t *criar_fila() {
	fila_t *f = (fila_t*)malloc(sizeof(fila_t));
	assert(f != NULL);
	f->inicio = 0;
	f->fim = 0;
	f->total = 0;
	return(f);
}

bool inserir(fila_t *f, int x) {
	if(!esta_cheia(f)) {
		f->itens[f->fim] = x;
		f->fim = (f->fim + 1) % TAM_FILA;
		f->total++;
		return(true);
	}
	return(false);
}

bool remover(fila_t *f, int *x) {
	if(!esta_vazia(f)) {
		*x = f->itens[f->inicio];
		f->inicio = (f->inicio + 1) % TAM_FILA;
		f->total--;
		return(true);
	}
	return(false);
}

bool esta_vazia(fila_t *f) {
	assert(f != NULL);
	return(f->total == 0);
}

bool esta_cheia(fila_t *f) {
	assert(f != NULL);
	return(f->total == TAM_FILA);
}

int tamanho(fila_t *f) {
	assert(f != NULL);
	return(f->total);
}

void destruir_fila(fila_t *f) {
	if(f != NULL){
		free(f);
	}
}
