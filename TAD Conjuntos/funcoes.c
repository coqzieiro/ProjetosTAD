#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void criar_conjunto(CONJUNTO *pA){
    for (int i=0; i<N; i++){
        (*pA).conjunto[i] = 0;
    }
}

CONJUNTO uniao(CONJUNTO pA, CONJUNTO pB){
    CONJUNTO pC;
    for(int i=0; i<N; i++){
        pC.conjunto[i] = pA.conjunto[i];
        if (pA.conjunto[i] == 0) break; // copia elementos do conjunto pA para pC, parando quando encontrar 0
    }
    for(int j=0; j <N; j++) {
        pC.conjunto[j] = pB.conjunto[j];
        if(pB.conjunto[j] == 0) break; // adiciona elementos do conjunto pB a pC, parando quando encontrar 0
    }
    return(pC); // retorna a uniao dos conjuntos pA e pB em pC
}

CONJUNTO interseccao(CONJUNTO pA, CONJUNTO pB){
    CONJUNTO pC;
    int i = 0;
    for(int k=0; k<N && pA.conjunto[k]!=0; k++){
        if (membro(pA.conjunto[k], &pB)){
            pC.conjunto[i] = pA.conjunto[k];
            i++;
        }
    }
    pC.conjunto[i] = 0; // adiciona zero ao final do conjunto resultante
    return(pC); // retorna a interseção dos conjuntos pA e pB em pC
}

CONJUNTO diferenca(CONJUNTO pA, CONJUNTO pB){
    CONJUNTO pC;
    int i = 0;
    for(int k=0; k<N && pA.conjunto[k]!=0; k++){
        if(!membro(pA.conjunto[k], &pB)){
            pC.conjunto[i] = pA.conjunto[k];
            i++;
        }
    }
    pC.conjunto[i] = 0; // adiciona zero ao final do conjunto resultante
    return(pC); // retorna a diferença dos conjuntos pA e pB em pC
}

int membro(int elemento, CONJUNTO *pA) {
    for(int i=0; i<N; i++){
        if ((*pA).conjunto[i] == elemento) {
            return(1); // retorna 1 se o elemento estiver no conjunto, caso contrario, retorna 0
        }
    }
    return(0);
}

int inserir(int elemento, CONJUNTO *pA){
    if (membro(elemento, pA) == 0){
        for (int i=0; i<N; i++){
            if((*pA).conjunto[i] == 0){
                (*pA).conjunto[i] = elemento;
                return(1); // insere o elemento no conjunto e retorna 1 se for bem-sucedido, caso contrario, retorna 0
            }
        }
    }
    return(0);
}

int remover(int elemento, CONJUNTO *pA){
    if (membro(elemento, pA) == 1){
        for(int i=0; i<N; i++){
            if((*pA).conjunto[i] == elemento){
                (*pA).conjunto[i] = 0;
                return(1); // remove o elemento do conjunto e retorna 1 se for bem-sucedido, caso contrario, retorna 0
            }
        }
    }
    return(0);
}

void atribuir(CONJUNTO *pA, CONJUNTO *pB){
    for(int i=0; i<N; i++){
        (*pB).conjunto[i] = (*pA).conjunto[i];
    }
}

int minimo(CONJUNTO *pA){
    int minimo = (*pA).conjunto[0];
    for(int i=0; i<N; i++){
        if ((*pA).conjunto[i]<minimo && (*pA).conjunto[i]!=0){
            minimo = (*pA).conjunto[i];
        }
    }
    return(minimo); // retorna o valor minimo no conjunto pA
}

int maximo(CONJUNTO *pA){
    int maximo = (*pA).conjunto[0];
    for (int i = 0; i < N; i++) {
        if ((*pA).conjunto[i]>maximo && (*pA).conjunto[i]!=0){
            maximo = (*pA).conjunto[i];
        }
    }
    return(maximo); // retorna o valor máximo no conjunto pA
}

int igual(CONJUNTO *pA, CONJUNTO *pB){
    for(int i=0; i<N; i++){
        if ((*pA).conjunto[i] != (*pB).conjunto[i]){
            return(0); // retorna 0 se os conjuntos pA e pB não forem iguais, caso contrario, retorna 1
        }
    }
    return(1); // retorna 1 se os conjuntos pA e pB forem iguais
}

void liberar(CONJUNTO *pA){
    for(int i=0; i<N; i++){
        (*pA).conjunto[i] = 0; // define todos os elementos do conjunto como zero
    }
}

void imprimir(CONJUNTO *pA){
    for(int i=0; i<N; i++){
        if((*pA).conjunto[i]!=0){
            printf("%d ", (*pA).conjunto[i]); // imprime os elementos nao nulos do conjunto
        }
    }
    printf("\n");
}