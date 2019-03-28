#include <stdlib.h>
#include <stdio.h>

// #include "lista.h"
#include "grafo.h"
// #include "mapa.h"

int main(int argc, char **argv) {
  printf("To be implemented\n\n");
  grafo g = constroi_grafo();
  
  // printf("Grafo: %s \n", g->nome);
  // printf("Age: %d \n", g->age);
  
  printf("\n");
  
  vertice root = g->raiz, f1, f2, f3, n1;
  f1 = novo_vertice("filho 1", root);
  f2 = novo_vertice("filho 2", root);
  f3 = novo_vertice("filho 3", root);
  n1 = novo_vertice("neto 1", f1);
  
  printf("\n");
  
  printf("Graph Root: %s \n", root->nome);
  printf("Edge 1: %s \n", f1->nome);
  printf("Edge 2: %s \n", f2->nome);
  printf("Edge 3: %s \n", f3->nome);
  printf("Edge 4: %s \n", n1->nome);
  
  insere_lista(f1, root->filhos);
  insere_lista(f2, root->filhos);
  insere_lista(f3, root->filhos);
  insere_lista(n1, f1->filhos);
  
  printf("\n");
  
  printf("Raiz:\n"); printf("\t\"%s\"\n", g->raiz->nome);
  printf("\nFilhos de %s:\n", root->nome); imprime_filhos(root);
  printf("\nFilhos de %s:\n", f1->nome);imprime_filhos(f1);
  printf("\nFilhos de %s:\n", f2->nome);imprime_filhos(f2);
  printf("\nFilhos de %s:\n", f3->nome);imprime_filhos(f3);
  
  printf("\n");
  
  // printf("Pai de %s: %s\n", root->nome, root->pai->nome);
  printf("Pai de %s: %s\n", f1->nome, f1->pai->nome);
  printf("Pai de %s: %s\n", f2->nome, f2->pai->nome);
  printf("Pai de %s: %s\n", f3->nome, f3->pai->nome);
  printf("Pai de %s: %s\n", n1->nome, n1->pai->nome);
  
  return 0;
  // int cor;
  // int semente;
  // int tmp;
  // tmapa m;

  // if(argc < 4 || argc > 5) {
  //   printf("uso: %s <numero_de_linhas> <numero_de_colunas> <numero_de_cores> [<semente_aleatoria>]\n", argv[0]);
  //   exit(1);
  // }

  // m.nlinhas = atoi(argv[1]);
  // m.ncolunas = atoi(argv[2]);
  // m.ncores = atoi(argv[3]);

  // if(argc == 5)
  //   semente = atoi(argv[4]);
  // else
  //   semente = 0;
  // gera_mapa(&m, semente);

  // mostra_mapa_cor(&m);

  // printf("escolha a posição de referência\n");
  // printf("linha: ");
  // scanf("%d", &tmp);
  // m.lref = tmp - 1;
  // printf("coluna: ");
  // scanf("%d", &tmp);
  // m.cref = tmp - 1;
  
  // cor = m.mapa[m.lref][m.cref];
  
  // while(cor != -1) {
  //   pinta_mapa(&m, cor);
  //   mostra_mapa_cor(&m);
  //   printf("cor: ");
  //   scanf("%d", &cor);
  // }
  // return 0;
}
