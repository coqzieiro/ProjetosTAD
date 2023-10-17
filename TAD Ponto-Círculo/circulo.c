#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "circulo.h"

// funcao para criar um circulo
CIRCULO *circulo_criar(PONTO *p, float raio) {
    CIRCULO *circ = (CIRCULO *)malloc(sizeof(CIRCULO));
    if (circ != NULL) {
        circ->centro = p;
        circ->raio = raio;
        return circ;
    } else {
        return(NULL);
    }
}

// funcao para apagar um circulo
void circulo_apagar(CIRCULO *circ){
    free(circ);
}

// funcao para calcular a area de um circulo
float circulo_area(CIRCULO *circ){
    float area = 3.14 * circ->raio * circ->raio;
    return(area);
}

// funcao para calcular a distancia entre um ponto e o centro de um circulo
float circulo_distancia(PONTO *p, CIRCULO *circ){
    float dist = sqrt(pow(p->x - circ->centro->x, 2) + pow(p->y - circ->centro->y, 2));
    return(dist);
}

// funcao para comparar a distancia com o raio do circulo
void circulo_compara(float dist, float raio){
    setlocale(LC_ALL, "Portuguese");
    if (dist > raio) {
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    } else if (dist == raio) {
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    } else {
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }
}