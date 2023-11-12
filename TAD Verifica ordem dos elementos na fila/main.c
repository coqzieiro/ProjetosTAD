#include <stdio.h>
#include <stdbool.h>
#include "fila.h"

// Define a função esta_ordenada, que verifica se os elementos de uma fila estão ordenados de forma crescente
bool esta_ordenada(fila_t *f){
    int x, y;
    bool ordenada = true;

    // Verifica se a fila não está vazia
    if (!esta_vazia(f)){
        // Remove o primeiro elemento da fila e armazena em x
        remover(f, &x);
        // Enquanto a fila não estiver vazia
        while (!esta_vazia(f)){
            // Remove o próximo elemento da fila e armazena em y
            remover(f, &y);
            // Se y é menor que x, a fila não está ordenada
            if (y < x) {
                ordenada = false;
                break;
            }
            // Atualiza o valor de x com o valor de y
            x = y;
        }
        // Reinserir o último elemento removido na fila
        inserir(f, x);
    }

    // Retorna true se a fila está ordenada, ou false caso contrário
    return(ordenada);
}

int main(void){
    fila_t *f = criar_fila();
    int i, num;

    printf("Insira 5 elementos na fila: ");
    for (i = 1; i <= 5; i++) {
        scanf("%d", &num);
        inserir(f, num);
    }

    if (esta_ordenada(f))
        printf("A fila esta ordenada de forma crescente.\n");
    else
        printf("A fila nao esta ordenada de forma crescente.\n");

    destruir_fila(f);
    return(0);
}