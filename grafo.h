#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "lista.h"
#include "mapa.h"

typedef struct grafo *grafo; 
typedef struct vertice *vertice;


struct vertice {
  int id;
 
  tmapa estado;
  int cor;
  int escore;
  int profundidade;
  vertice pai;
  lista filhos; // lista de vizinhos de saida 
  int rota[5000];
};

struct grafo {
    unsigned int numVertice;
    vertice raiz;
    lista vertices;
};

grafo constroi_grafo();
vertice constroi_vertice (int id, vertice pai, tmapa m);
no novo_vertice(grafo g, vertice pai, tmapa *m, lista fronteira );
no expande_vertices(grafo g, no pai, int cores, lista fronteira);
lista vertices(grafo g);
void imprime_filhos(vertice ver);
void imprime_lista(lista l);

#endif