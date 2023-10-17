#ifndef FUNCOES_H
    #define FUNCOES_H

    #define N 5 // delimita o numero de elementos que cada conjunto possui

    struct conj{ // define uma estrutura que representa um conjunto
        int conjunto[N]; // um vetor de inteiros para armazenar os elementos
    };

    typedef struct conj CONJUNTO; // define um tipo CONJUNTO para simplificar a declaracao de variaveis

    void criar_conjunto(CONJUNTO *p); // declara uma funcao que cria um conjunto vazio
    CONJUNTO uniao(CONJUNTO pA, CONJUNTO pB); // declara uma funcao que retorna a união de dois conjuntos
    CONJUNTO interseccao(CONJUNTO pA, CONJUNTO pB); // declara uma função que retorna a interseccao de dois conjuntos
    CONJUNTO diferenca(CONJUNTO pA, CONJUNTO pB); // declara uma funcao que retorna a diferenca de dois conjuntos
    int membro(int elemento, CONJUNTO *pA); // declara uma funcao que verifica se um elemento pertence a um conjunto
    int inserir(int elemento, CONJUNTO *pA); // declara uma funcao que insere um elemento em um conjunto
    int remover(int elemento, CONJUNTO *pA); // declara uma funcao que remove um elemento de um conjunto
    void atribuir(CONJUNTO *pA, CONJUNTO *pB); // declara uma funcao que atribui os elementos de um conjunto a outro
    int minimo(CONJUNTO *pA); // declara uma funcao que retorna o menor elemento de um conjunto
    int maximo(CONJUNTO *pA); // declara uma funcao que retorna o maior elemento de um conjunto
    int igual(CONJUNTO *pA, CONJUNTO *pB); // declara uma função que verifica se dois conjuntos sao iguais
    void liberar(CONJUNTO *pA); // declara uma funcao que libera a memoria alocada para um conjunto
    void imprimir(CONJUNTO *pA); // declara uma funcao que imprime os elementos de um conjunto na tela
#endif
