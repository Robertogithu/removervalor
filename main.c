#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int valor;
	struct node* prox;
} NODO;

typedef struct {
	NODO* inicio;
	NODO* fim;
} LISTA;

void iniciarLista (LISTA* l) {
	l->inicio = NULL;
	l->fim = NULL;
}

void reiniciarLista (LISTA* l) {
	NODO* aux = l->inicio;
	while (aux != NULL) {
		NODO* apagar = aux;		
		aux = aux->prox;
		
		free(apagar);
	}
	
	iniciarLista(l);
}

int tamanho(LISTA* l) {
	NODO* aux = l->inicio;
	int tam = 0;
	
	while (aux != NULL) {
		tam++;
		aux = aux->prox;
	}
	
	return tam;
}

void printLista(LISTA* l) {
	NODO* i = l->inicio;
	
	printf("LISTA: \n\n");
	
	while (i != NULL) {
		printf("|_%d_|", i->valor);
		i = i->prox;
	}
	
	printf("\n\n");
}

void inserir(LISTA* l, int valor) {
	NODO* novo = (NODO*) malloc(sizeof(NODO));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(l->inicio == NULL) l->inicio = novo;
	else l->fim->prox = novo;
	
	l->fim = novo;
}

void remover(LISTA* l) {
  NODO* aux = l->inicio;
	
  if (l->inicio == NULL) return; // A LISTA ESTÁ VAZIA

  if (l->inicio->prox == NULL) {
    free(l->inicio);

    l->inicio = NULL;
    l->fim = NULL;
  } else {
    while (aux != NULL) {
      if (aux->prox->prox == NULL) {
        free(aux->prox);
        aux->prox = NULL;
        l->fim = aux;
      }

		  aux = aux->prox;
	  }
  }
}

void removerValor(LISTA* l, int valor) {
  NODO* i = l->inicio;
	
	//printf("LISTA: \n\n");
	
	while (i == NULL) {
		//printf("|_%d_|", i->valor);

		i = i->prox;
}

int main() {
	LISTA lista;
	
	iniciarLista(&lista);
	
	inserir(&lista, 1);
	inserir(&lista, 2);
	inserir(&lista, 3);
	
	remover(&lista);
  remover(&lista);
  remover(&lista);
	
	// reiniciarLista(&fila);
	
	printLista(&lista);
}