#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"
#include "grafo.h"
#include "mapa.h"
#include "aux.h"

int main(int argc, char **argv) {

  int cor, semente, tmp, cores, final;
  tmapa m;
  lista fronteira = constroi_lista();
  grafo g = constroi_grafo();
  vertice v;
  no no;


  // if(argc < 4 || argc > 5) {
  //   printf("uso: %s <numero_de_linhas> <numero_de_colunas> <numero_de_cores> [<semente_aleatoria>]\n", argv[0]);
  //   exit(1);
  // }

  // m.nlinhas = atoi(argv[1]);
  // m.ncolunas = atoi(argv[2]);
  // m.ncores = atoi(argv[3]);
  
  m.nlinhas = 5;
  m.ncolunas = 5;
  m.ncores = 3;
  
  final = m.nlinhas * m.ncolunas;
  cores = m.ncores;
  
  printint("Cores", cores);
  printint("Estado final", final);

  if(argc == 5)
    semente = atoi(argv[4]);
  else
    semente = 0;
  gera_mapa(&m, semente);
  
  m.lref = 0;
  m.cref = 0;
  
  //Inicia Estado Inicial (Vertice 0)
  no = novo_vertice(g, NULL, &m, fronteira);
  v = conteudo(no);
  imprime_vertice(v);
  
  expande_vertices(g, no, cores, fronteira);
  
  // m = *aloca_mapa(&v->estado);
  // pinta_mapa(&m, 4);
  // no = novo_vertice(g, v, &m, fronteira);


  exit(0);
  
  printf("escolha a posição de referência\n");
  printf("linha: ");
  scanf("%d", &tmp);
  m.lref = tmp - 1;
  printf("coluna: ");
  scanf("%d", &tmp);
  m.cref = tmp - 1;
  
  cor = m.mapa[m.lref][m.cref];
  
  
  while(cor != -1) {
    pinta_mapa(&m, cor);
    mostra_mapa_cor(&m);
    // printf("\n");
    // mostra_mapa_cor(&n);
    printf("cor: ");
    scanf("%d", &cor);
  }
  return 0;
}
// vertice novo_vertice(grafo g, vertice pai, tmapa *m, lista fronteira ) {
//     vertice v = constroi_vertice(tamanho_lista(g->vertices), pai, m);
//     insere_lista(v, g->vertices);
//     insere_lista(v, fronteira);
//     if( pai != NULL) {
//       insere_lista(pai->filhos);
//     }
// }
