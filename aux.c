#include <stdlib.h>
#include <stdio.h>

#include "aux.h"

void printint (char* s, int i) {
  printf("%s: %d\n",s, i);
}

void imprime_vertice(vertice v) {
  printint("Vertice", v->id);
  mostra_mapa_cor(&v->estado);
  printint("Flood: ", v->escore); printf("\n");
}

