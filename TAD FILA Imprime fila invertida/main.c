#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// funcao para imprimir a fila na ordem inversa
void imprimir_fila(fila_t *f){
    void *x;  // declara um ponteiro generico
    if(!esta_vazia(f)){  // verifica se a fila nao esta vazia
        remover(f, &x);  // remove um elemento da fila
        imprimir_fila(f);  // chama a funcao recursivamente para imprimir o proximo elemento
        printf("%d ", *((int*)x));  // imprime o elemento removido
        inserir(f, x);  // insere o elemento de volta na fila
    }
}

int main(void){
    fila_t *f = criar_fila();  // cria uma nova fila
    int i, N;  // declara variaveis para o loop e para armazenar o numero de elementos

    printf("Digite o numero de elementos: ");  // solicita ao usuário que insira o numero de elementos
    scanf("%d", &N);  // le a entrada do usuário

    // Loop para inserir elementos na fila
    for (i=1; i<=N; i++){
        int *p = malloc(sizeof(int));  // aloca memoria para um novo inteiro
        scanf("%d", p);  // le a entrada do usuário e armazena no espaco alocado
        inserir(f, p);  // insere o ponteiro para o inteiro na fila
    }

    printf("Fila invertida: ");  // imprime uma mensagem antes de imprimir a fila
    imprimir_fila(f);  // chama a funcao para imprimir a fila na ordem inversa
    printf("\n");  // imprime uma nova linha

    destruir_fila(f);  // destroi a fila e libera a memoria alocada
    return(0);  // retorna 0 indicando que o programa terminou com sucesso
}