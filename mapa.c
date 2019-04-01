#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mapa.h"

int** aloca_matriz_int(int l, int c) {
  int i;
  int **m;
  
  m = (int**) malloc(l * (sizeof(int*) + c * sizeof(int)));
  if(!m) {
    printf("falta memoria\n");
    exit(1);
  }
  m[0] = (int *) &m[l];
  for(i = 1; i < l; i++)
    m[i] = &m[i - 1][c];
  return m;
}

tmapa * aloca_mapa(tmapa *mo) {
  tmapa *md;

  md = (tmapa *) malloc(sizeof(tmapa));
  if(!md) {
    printf("falta memoria\n");
    exit(1);
  }
  md->nlinhas = mo->nlinhas;
  md->ncolunas = mo->ncolunas;
  md->ncores = mo->ncores;
  md->lref = mo->lref;
  md->cref = mo->cref;
  md->cmax = mo->cmax;
  md->lmax = mo->lmax;
  md->mapa = aloca_matriz_int(md->nlinhas, md->ncolunas);
  
  for(int i = 0; i < mo->nlinhas; i++) {
    for(int j = 0; j < mo->ncolunas; j++)
        md->mapa[i][j] = mo->mapa[i][j];
  }
  
  return md;
}

void copia_mapa(tmapa *m, tmapa *n) {
  int i, j;
  n->nlinhas = m->nlinhas;
  n->ncolunas = m->ncolunas;
  n->ncores = m->ncores;
  n->cmax = m->cmax;
  n->lmax = m->lmax;
  
  n->mapa = aloca_matriz_int(n->nlinhas, n->ncolunas);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
        n->mapa[i][j] = m->mapa[i][j];
  }
}

void libera_mapa(tmapa *m)  {
  free(m->mapa);
  free(m);
}

void gera_mapa(tmapa *m, int semente) {
  int i, j;
  m->cmax = m->ncolunas - 1;
  m->lmax = m->nlinhas -1;

  if(semente)
    srand(semente);  
  else
    srand(time(NULL));  
  m->mapa = aloca_matriz_int(m->nlinhas, m->ncolunas);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      m->mapa[i][j] = 1 + rand() % m->ncores;
  }
}

void carrega_mapa(tmapa *m) {
  int i, j;

  scanf("%d", &(m->nlinhas));
  scanf("%d", &(m->ncolunas));
  scanf("%d", &(m->ncores));
  m->cmax = m->ncolunas - 1;
  m->lmax = m->nlinhas -1;
  m->mapa = aloca_matriz_int(m->nlinhas, m->ncolunas);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      scanf("%d", &(m->mapa[i][j]));
  }
}

void mostra_mapa(tmapa *m) {
  int i, j;

  printf("%d %d %d\n", m->nlinhas, m->ncolunas, m->ncores);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      if(m->ncores > 10)
	printf("%02d ", m->mapa[i][j]);
      else
	printf("%d ", m->mapa[i][j]);
    printf("\n");
  }
}

void mostra_mapa_cor(tmapa *m) {
  int i, j;
  char* cor_ansi[] = { "\x1b[0m",
                       "\x1b[31m", "\x1b[32m", "\x1b[33m",
                       "\x1b[34m", "\x1b[35m", "\x1b[36m",
                       "\x1b[37m", "\x1b[30;1m", "\x1b[31;1m",
                       "\x1b[32;1m", "\x1b[33;1m", "\x1b[34;1m",
                       "\x1b[35;1m", "\x1b[36;1m", "\x1b[37;1m" };

  if(m->ncores > 15) {
    mostra_mapa(m);
    return;
  }
  printf("%d %d %d\n", m->nlinhas, m->ncolunas, m->ncores);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      if(m->ncores >= 10)
        printf("%s%02d%s ", cor_ansi[m->mapa[i][j]], m->mapa[i][j], cor_ansi[0]);
      else
        printf("%s%d%s ", cor_ansi[m->mapa[i][j]], m->mapa[i][j], cor_ansi[0]);
    printf("\n");
  }
}

int conta_flood(tmapa *m, int i, int j, int cor, int dir) {
  int res = conta(m, i, j, cor, dir);
  // mostra_mapa_cor(m);
  // int res = 1;
  return res;
}

int conta(tmapa *m, int i, int j, int cor, int dir) {
  int **mat = m->mapa;
  int count = 0;
  // mostra_mapa_cor(m); 
  if (i > m->lmax) i = 0;
  else if (i < 0) i = m->lmax;
  
  if (j > m->cmax) j = 0;
  else if (j < 0 ) j = m->cmax;
  if(mat[i][j] != cor) return count;
  count++;
  // mat[i][j] = mat[i][j] * -1;
  mat[i][j] = 0;
  
  dir == 1 ? (count += 0) : (count += conta_flood(m, i-1, j, cor, 3));
  dir == 2 ? (count += 0) : (count += conta_flood(m, i, j+1, cor, 4));
  dir == 3 ? (count += 0) : (count += conta_flood(m, i+1, j, cor, 1));
  dir == 4 ? (count += 0) : (count += conta_flood(m, i, j-1, cor, 2));
  // printf("i: %d j: %d\n", i, j);

  return count;
}

void pinta(tmapa *m, int l, int c, int fundo, int cor) {
  int rl, rc;

  m->mapa[l][c] = cor;
  rl = (l + 1) % m->nlinhas;
  rc = c;
  if(m->mapa[rl][rc] == fundo)
    pinta(m, rl, rc, fundo, cor);
  rl = (m->nlinhas + l - 1) % m->nlinhas;
  rc = c;
  if(m->mapa[rl][rc] == fundo)
    pinta(m, rl, rc, fundo, cor);
  rl = l;
  rc = (c + 1) % m->ncolunas;
  if(m->mapa[rl][rc] == fundo)
    pinta(m, rl, rc, fundo, cor);
  rl = l;
  rc = (m->ncolunas + c - 1) % m->ncolunas;
  if(m->mapa[rl][rc] == fundo)
    pinta(m, rl, rc, fundo, cor);
}

void pinta_mapa(tmapa *m, int cor) {
  int fundo;

  fundo = m->mapa[m->lref][m->cref];
  if(cor == fundo)
    return;
  pinta(m, m->lref, m->cref, fundo, cor);
}
// int conta(tmapa *m, int i, int j, int cor, int dir)
int ponto_inicial (int lref, int cref, tmapa* m) {
  int k = 0, conta, cor;
  int **mat = m->mapa;
  // printf("lmax: %d cmax: %d\n", m->lmax, m->cmax);
  for(int i = 0; i <= m->lmax; i++) {
    // printf("i: %d\n", i);
    for(int j = 0; j <= m->cmax; j++) {
      // printf("  j: %d ", j);
      cor = mat[i][j];
      conta = conta_flood(m, i, j, cor, 0);
      pinta_mapa(m, cor);
      if (conta > k) {
        k = conta;
        lref = i;
        cref = j;
      }
    }
  }
  printf("lref: %d, cref: %d\n", lref, cref );
  printf("k: %d\n ", k);
  return k;
}
