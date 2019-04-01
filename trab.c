#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lista.h"
#include "grafo.h"
#include "mapa.h"
#include "aux.h"

//cat exemplo plano | ./verifica ; echo $?
int main(int argc, char **argv) {

  int cores, final;
  tmapa m;
  lista fronteira = constroi_lista();
  grafo g = constroi_grafo();
  vertice v;
  no no, n;

  carrega_mapa(&m);
  
  final = m.nlinhas * m.ncolunas;
  cores = m.ncores;
  
  int* arr = malloc((final/4) * sizeof(int));
  arr[0] = 0;
  
  m.lref = 0;
  m.cref = 0;
  // mostra_mapa_cor(&m);
  // ponto_inicial(m.lref, m.cref, &m);
  // exit(0);
  
  //Inicia Estado Inicial (Vertice 0)
  no = novo_vertice(g, NULL, &m, fronteira);
  v = conteudo(no);
  // imprime_vertice(v);
  
  // printf("\n\n");
  while (!vazia(fronteira)) {
    no = expande_vertices(g, no, cores, fronteira);
    for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
      no = checa_escore(no, n);
    }
    v = conteudo(no);
    // imprime_vertice(v);
    arr[0]++;
    arr[arr[0]] = v->cor;
    if(v->escore == final) break;
  }
  // printint("Score", v->escore); printf("\n");

  imprime_array(arr, &m);
}
