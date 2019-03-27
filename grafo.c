#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "grafo.h"

grafo constroi_grafo(char* g_name, int g_age) {

  grafo g = malloc(sizeof(struct grafo));

  if ( ! g ) 
    return NULL;
    
  g->raiz = novo_vertice("first V", NULL);

  g->nome = g_name;
  g->age = g_age;

  return g;
}

vertice novo_vertice (char *nome_v, vertice pai) {
	vertice v = malloc(sizeof(*v));
	if ( !v )
		return NULL;

	//guarda o nome do vértice
	v->nome = malloc(sizeof(char)*(strlen(nome_v)+1));
	strcpy(v->nome,nome_v);

	v->pai = pai;
	v->filhos  = constroi_lista();

	return v;
}

void imprime_filhos(vertice ver) {
  lista l = ver->filhos;
  for(no n = primeiro_no(l); n; n = proximo_no(n)) {
    vertice v = conteudo(n);
    printf("\t\"%s\"\n", v->nome);
  }
}