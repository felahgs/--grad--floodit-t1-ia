#ifndef __MAPA_H__
#define __MAPA_H__

typedef struct {
  int nlinhas;
  int ncolunas;
  int ncores;
  int lmax;
  int cmax;
  int lref;
  int cref;
  int **mapa;
} tmapa;

tmapa* aloca_mapa(tmapa*);
void libera_mapa(tmapa*);
void gera_mapa(tmapa*, int);
void copia_mapa(tmapa *m, tmapa *n);
void carrega_mapa(tmapa*);
void mostra_mapa(tmapa*);
void mostra_mapa_cor(tmapa*);
int conta_flood(tmapa *m, int i, int j, int cor, int dir);
int conta(tmapa *m, int i, int j, int cor, int dir);
void pinta(tmapa *m, int l, int c, int fundo, int cor);
void pinta_mapa(tmapa*, int);


#endif
