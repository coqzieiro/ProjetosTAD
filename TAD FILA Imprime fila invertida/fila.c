#include "fila.h"

struct fila{
	int inicio, fim, total;  // variaveis para controlar o inicio, fim e total de elementos na fila
	void *itens[TAM_FILA];  // array para armazenar os elementos da fila
};

fila_t *criar_fila(){
	fila_t *f = (fila_t*)malloc(sizeof(fila_t)); // aloca memoria para a nova fila
	assert(f != NULL); // verifica se a alocação de memoria foi bem-sucedida
	f->inicio = 0; // inicializa o inicio da fila
	f->fim = 0; // inicializa o fim da fila
	f->total = 0; // inicializa o total de elementos na fila
	return(f); // retorna a nova fila
}

bool inserir(fila_t *f, void *x){
	if(!esta_cheia(f)){ // verifica se a fila nao esta cheia
		f->itens[f->fim] = x; // insere o elemento no fim da fila
		f->fim = (f->fim+1)%TAM_FILA; // atualiza o fim da fila
		f->total++; // incrementa o total de elementos na fila
		return(true); // retorna verdadeiro indicando que a inserção foi bem-sucedida
	}
	return(false); // retorna falso se a fila estiver cheia
}

bool remover(fila_t *f, void **x){
	if(!esta_vazia(f)) { // verifica se a fila nao esta vazia
		*x = f->itens[f->inicio]; // remove o elemento do inicio da fila
		f->inicio = (f->inicio+1)%TAM_FILA; // atualiza o inicio da fila
		f->total--; // decrementa o total de elementos na fila
		return(true); // retorna verdadeiro indicando que a remocao foi bem-sucedida
	}
	return(false); // retorna falso se a fila estiver vazia
}

bool esta_vazia(fila_t *f){
	assert(f != NULL); // Verifica se a fila nao eh nula
	if(f->total == 0) // Se o total de elementos na fila for zero,
		return(true); // retorna verdadeiro
	return(false); // caso contrario, retorna falso
}

bool esta_cheia(fila_t *f){
	assert(f != NULL); // verifica se a fila nao eh nula
	if(f->total == TAM_FILA) // se o total de elementos na fila for igual ao tamanho maximo,
		return(true); // retorna verdadeiro
	return(false); // caso contrario, retorna falso
}

int tamanho(fila_t *f){
	assert(f != NULL); // verifica se a fila nao eh nula
	return(f->total); // retorna o total de elementos na fila
}

void destruir_fila(fila_t *f){
	if(f != NULL) // se a fila nao eh nula,
		free(f); // libera a memoria alocada para ela
}