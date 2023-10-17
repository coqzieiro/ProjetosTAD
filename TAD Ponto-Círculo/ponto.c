#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "ponto.h"

// funcao para criar um ponto
PONTO *ponto_criar(float x, float y){
    PONTO *p = (PONTO*)malloc(sizeof(PONTO)); // aloca o tamanho do ponto dinamicamente
    if (p != NULL) {
        p->x = x;
        p->y = y;
        return(p);
    } else {
        return(NULL);
    }
}

// funcao para apagar um ponto
void ponto_apagar(PONTO *p){
    free(p);
}

// funcao para definir as coordenadas de um novo ponto
bool ponto_set(PONTO *p, float x, float y){
    if (p != NULL) {
        p->x = x; 
        p->y = y;
        return(true);
    } else {
        return(false);
    }
}