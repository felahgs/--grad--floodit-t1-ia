#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lista.h"
#include "grafo.h"
#include "mapa.h"
#include "aux.h"

int main(int argc, char **argv) {

  int cores, final;
  tmapa m;
  lista fronteira = constroi_lista();
  grafo g = constroi_grafo();
  vertice v, flood_max;
  no no, n;

  carrega_mapa(&m);
  
  final = m.nlinhas * m.ncolunas;
  cores = m.ncores;
  
  int* arr = malloc((final/4) * sizeof(int));
  arr[0] = 0;
  
  
  m.lref = 0;
  m.cref = 0;
  ponto_inicial(&m);
  
  //Inicia Estado Inicial (Vertice 0)
  no = novo_vertice(g, NULL, &m, fronteira);
  flood_max = conteudo(no);
  v = conteudo(no);
  
  while (flood_max->escore != final ) {
    for (int c = 0; c < 3; c++){ 
      for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
        v = conteudo(n); 
        if(v->escore > flood_max->escore) {
          flood_max = v;
          expande_vertices(g, n, cores, fronteira);
        }
        else {
          expande_vertices(g, n, cores, fronteira);
        }
      }
    }
    for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
        v = conteudo(n);
        if(v->escore > flood_max->escore) {
          flood_max = v;
          remove_no(fronteira, n, NULL);
        }
        else {
          free(v->estado.mapa);
          remove_no(fronteira, n, NULL);
        }
    }
    insere_lista(flood_max, fronteira);
  }
  imprime_resultado(flood_max->rota, &m);
}
