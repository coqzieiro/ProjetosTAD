#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "ponto.h"
#include "circulo.h"

int main(void){
    setlocale(LC_ALL, "Portuguese"); // configura a saida do programa para a lingua portuguesa
    float p1_x, p1_y, p2_x, p2_y, raio;
    scanf("%f %f %f %f %f", &p1_x, &p1_y, &p2_x, &p2_y, &raio); // le as informações do ponto, centro do ciculo e raio
    
    // criacao dos pontos e do círculo
    PONTO *p_normal = ponto_criar(p1_x, p1_y); // cria um ponto generico
    PONTO *p_centro = ponto_criar(p2_x, p2_y); // cria o ponto do centro
    CIRCULO *circulo_certo = circulo_criar(p_centro, raio); // cria o circulo com base no centro e no raio

    // calculo da distância e comparacao com o raio
    float dist = circulo_distancia(p_normal, circulo_certo);
    circulo_compara(dist, raio); // chama a funcao que compara a distância do raio do ciculo e o ponto generico

    // liberacao da memoria alocada
    ponto_apagar(p_normal);
    ponto_apagar(p_centro);
    circulo_apagar(circulo_certo);

    return(0);
}