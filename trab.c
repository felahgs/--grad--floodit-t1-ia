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
  vertice v, flood_max;
  no no, n;

  carrega_mapa(&m);
  
  final = m.nlinhas * m.ncolunas;
  cores = m.ncores;
  
  int* arr = malloc((final/4) * sizeof(int));
  arr[0] = 0;
  
  
  ponto_inicial(&m);
  
  //Inicia Estado Inicial (Vertice 0)
  no = novo_vertice(g, NULL, &m, fronteira);
  flood_max = conteudo(no);
  v = conteudo(no);
  
  while (flood_max->escore != final ) {
  // imprime_lista(fronteira);
  // int it = 0;
  // printint("\niteration", it); it++;
  // printint("Fronteira", tamanho_lista(fronteira)); imprime_lista(fronteira);
  // printint("Grafo", tamanho_lista(g->vertices)); imprime_lista(g->vertices);
    for (int c = 0; c < 3; c++){ 
      for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
        v = conteudo(n); 
        if(v->escore > flood_max->escore) {
            flood_max = v;
        }
        expande_vertices(g, n, cores, fronteira);
        // printint("\niteration", it); it++;
        // printint("Fronteira", tamanho_lista(fronteira)); imprime_lista(fronteira);
        // printint("Grafo", tamanho_lista(g->vertices)); imprime_lista(g->vertices);
      }
    }
    for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
        v = conteudo(n);
        if(v->escore > flood_max->escore) {
          flood_max = v;
        }
        remove_no(fronteira, n, NULL);
        // printint("\niteration", it); it++;
        // printint("Fronteira", tamanho_lista(fronteira)); imprime_lista(fronteira);
        // printint("Grafo", tamanho_lista(g->vertices)); imprime_lista(g->vertices);
        // imprime_vertice(flood_max); exit(0);
    }
    insere_lista(flood_max, fronteira);
    // imprime_lista(fronteira);
    // imprime_vertice(flood_max); exit(0);
  }
  // imprime_vertice(flood_max);
  imprime_resultado(flood_max->rota, &m);
  // imprime_vertice(v);
  
  // while (!vazia(fronteira)) {
  //   no = expande_vertices(g, no, cores, fronteira);
  //   for(n = primeiro_no(fronteira); n; n = proximo_no(n)) {
  //     no = checa_escore(no, n);
  //   }
  //   v = conteudo(no);
  //   arr[0]++;
  //   arr[arr[0]] = v->cor;
  //   if(v->escore == final) break;
  // }

  // imprime_resultado(arr, &m);
}
