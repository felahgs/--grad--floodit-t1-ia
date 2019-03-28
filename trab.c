#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #include "lista.h"
// #include "grafo.h"
#include "mapa.h"

int main(int argc, char **argv) {

  int cor;
  int semente;
  int tmp;
  tmapa m;
  tmapa n;
  
  
  // if(argc < 4 || argc > 5) {
  //   printf("uso: %s <numero_de_linhas> <numero_de_colunas> <numero_de_cores> [<semente_aleatoria>]\n", argv[0]);
  //   exit(1);
  // }

  // m.nlinhas = atoi(argv[1]);
  // m.ncolunas = atoi(argv[2]);
  // m.ncores = atoi(argv[3]);
  
  m.nlinhas = 4;
  m.ncolunas = 4;
  m.ncores = 3;

  if(argc == 5)
    semente = atoi(argv[4]);
  else
    semente = 0;
  gera_mapa(&m, semente);
  copia_mapa(&m, &n);

  printf("m: %d %d %d\n", m.nlinhas, m.ncolunas, m.ncores);
  printf("n: %d %d %d\n", n.nlinhas, n.ncolunas, n.ncores);
  
  mostra_mapa_cor(&m);
  mostra_mapa_cor(&n);

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
    mostra_mapa_cor(&n);
    printf("cor: ");
    scanf("%d", &cor);
  }
  return 0;
}
