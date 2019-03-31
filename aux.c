#include <stdlib.h>
#include <stdio.h>

#include "aux.h"


void printint (char* s, int i) {
  printf("%s: %d\n",s, i);
}

void imprime_vertice(vertice v) {
  printint("Vertice", v->id);
  mostra_mapa_cor(&v->estado);
  printint("Profundidade", v->profundidade);
  printint("Cor", v->cor);
  printint("Flood", v->escore); printf("\n");
}

no checa_escore(no na, no nb) {
  vertice v1 = conteudo(na),
          v2 = conteudo(nb);
      
  if (v1->escore >= v2->escore) 
    return na;
  else 
    return nb;
}

void imprime_array(int *arr) {
  printf("n m %d\n", arr[0]);
  for (int i = 1; i <= arr[0]; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}