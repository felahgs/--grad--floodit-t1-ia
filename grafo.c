#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "grafo.h"
#include "aux.h"

grafo constroi_grafo() {

  grafo g = malloc(sizeof(struct grafo));

  if ( ! g ) 
    return NULL;
    
  g->vertices = constroi_lista();
  // g->raiz = novo_vertice("0, NULL);

  return g;
}

vertice constroi_vertice (int id, vertice pai, tmapa m) {
	vertice v = malloc(sizeof(*v));
	int i = m.lref,
	    j = m.cref,
	    cor = m.mapa[i][j];
	    pinta_mapa(&m, cor);
	if ( !v )
		return NULL;

  v->id = id;
	v->pai = pai;
	v->filhos  = constroi_lista();
	v->estado = m;
	v->cor = cor;
	v->escore = conta_flood(&m, m.lref, m.cref, cor, 0);
	pinta_mapa(&m, v->cor);

	return v;
}

no novo_vertice(grafo g, vertice pai, tmapa *m, lista fronteira ) {
    vertice v = constroi_vertice(tamanho_lista(g->vertices), pai, *m);
    insere_lista(v, g->vertices);
    insere_lista(v, fronteira);
    // v->rota = malloc(2 * sizeof(int*));
    if( pai != NULL) {
      v->profundidade = pai->profundidade + 1;
      insere_lista(v, pai->filhos);
      copia_array(pai->rota, v->rota);
      v->rota[0]++;
      v->rota[v->rota[0]] = v->cor;
    }
    else {
      v->profundidade = 0;
      v->rota[0] = 0;
    }
    no n = primeiro_no(fronteira);
    return n;
}

no expande_vertices(grafo g, no pai, int cores, lista fronteira) {
  vertice v = conteudo(pai);
  for(int i = 1; i <= cores; i++) {
    if (i == v->cor) continue;
    tmapa m = *aloca_mapa(&v->estado);
    pinta_mapa(&m, i);
    novo_vertice(g, v, &m, fronteira);
    
  }
  remove_no(fronteira, pai, NULL);
  return primeiro_no(fronteira);
}

lista vertices(grafo g) { return g->vertices; }

void imprime_filhos(vertice ver) {
  lista l = ver->filhos;
  for(no n = primeiro_no(l); n; n = proximo_no(n)) {
    vertice v = conteudo(n);
    printf("\t\"Vertice %d\"\n", v->id);
  }
}

void imprime_lista(lista l) {
  if (l->primeiro == NULL)
    printf("\tLista vazia\n");
  else 
    for(no n = primeiro_no(l); n; n = proximo_no(n)) {
      vertice v = conteudo(n);
      if (v->pai == NULL)
        printf("\t\"Vertice %d\" Vertice Raíz\n", v->id);
      else 
        printf("\t\"Vertice %d\" filho de \"Vertice %d\" Rota:", v->id, v->pai->id);
        imprime_array(v->rota);
    }
}

