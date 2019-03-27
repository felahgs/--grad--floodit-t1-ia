#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "lista.h"

typedef struct grafo *grafo; 
typedef struct vertice *vertice;


struct vertice {
  char* nome;
 
  int valor;
  vertice pai;
  lista filhos; // lista de vizinhos de saida 
};

struct grafo {
    char* nome;
    int age;
    unsigned int numVertice;

    vertice raiz;

    lista vertices;
};

//------------------------------------------------------------------------------


grafo constroi_grafo(char* g_name, int g_age);

vertice novo_vertice (char *nome_v, vertice pai);

void imprime_filhos(vertice ver);

#endif