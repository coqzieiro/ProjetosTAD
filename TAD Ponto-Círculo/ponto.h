#ifndef PONTO_H
    #define PONTO_H
    #include <stdbool.h> // inclusao da biblioteca de manipulacao de variaveis logicas

    typedef struct ponto_ PONTO; // definicao de um novo tipo PONTO via struct

    // prototipo das funcoes que criam, apagam e configuram um novo ponto
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);

    // definicao da struct ponto
    struct ponto_ {
        float x;
        float y;
    };

    // a struct ponto_ foi inclusa no arquivo ponto.h pois ela define a representação de um ponto, permitindo a abstração desse conceito

#endif