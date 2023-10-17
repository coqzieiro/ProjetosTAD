#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"

    struct circulo_ {
        PONTO *centro;
        float raio;
    };

    typedef struct circulo_ CIRCULO;

    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar(CIRCULO* circ);
    float circulo_area(CIRCULO* circ);
    float circulo_distancia(PONTO *p, CIRCULO *circ);
    void circulo_compara(float dist, float raio); 
#endif
