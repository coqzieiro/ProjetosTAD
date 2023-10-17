#include <stdio.h>
#include "funcoes.h"

int main(void){
    CONJUNTO p1, p2;
    criar_conjunto(&p1); // chama a funcao para criar o conjunto p1
    criar_conjunto(&p2); // chama a funcao para criar o conjunto p2
    printf("Digite os valores do conjunto A (insira 0 para finalizar): ");
    int elemento;
    int i = 0;
    do{
        scanf("%d", &elemento); // le um elemento do usuário
        if(elemento!=0){
            p1.conjunto[i] = elemento; // adiciona o elemento ao conjunto p1
            i++;
        }
    } while(elemento != 0); // continua lendo até que 0 seja inserido para finalizar

    printf("Digite os valores do conjunto B (insira 0 para finalizar): ");
    int j = 0;
    do {
        scanf("%d", &elemento); // le um elemento do usuario
        if (elemento!=0) {
            p2.conjunto[j] = elemento; // adiciona o elemento ao conjunto p2
            j++;
        }
    } while(elemento!=0); // continua lendo até que 0 seja inserido para finalizar

    CONJUNTO un = uniao(p1, p2); // calcula a união dos conjuntos p1 e p2
    CONJUNTO inter = interseccao(p1, p2); // calcula a interseção dos conjuntos p1 e p2
    CONJUNTO diff = diferenca(p1, p2); // calcula a diferença dos conjuntos p1 e p2

    printf("Uniao: ");
    imprimir(&un); // imprime a uniao
    printf("Interseccao: ");
    imprimir(&inter); // imprime a intersecao
    printf("Diferenca: ");
    imprimir(&diff); // imprime a diferenca
    printf("Maximo de A: %d, Minimo de A: %d\n", maximo(&p1), minimo(&p1)); // calcula e imprime o maximo e o minimo do conjunto p1
    printf("Maximo de B: %d, Minimo de B: %d\n", maximo(&p2), minimo(&p2)); // calcula e imprime o maximo e o minimo do conjunto p2
    return(0);
}