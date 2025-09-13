#include "listaSimbolos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
extern int yylineno;
extern int contadorCadenas;

struct PosicionListaRep {
  Simbolo dato;
  struct PosicionListaRep *sig;
};

struct ListaRep {
  PosicionLista cabecera;
  PosicionLista ultimo;
  int n;
};

typedef struct PosicionListaRep *NodoPtr;

// TABLA DE SIMBOLOS
Lista creaLS() {
  Lista nueva = malloc(sizeof(struct ListaRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  return nueva;
}


void liberaLS(Lista lista) {
  while (lista->cabecera != NULL) {
    NodoPtr borrar = lista->cabecera;
    lista->cabecera = borrar->sig;
    free(borrar);
  }
  free(lista);
}


void insertaLS(Lista lista, PosicionLista p, Simbolo s) {
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (lista->ultimo == p) {
    lista->ultimo = nuevo;
  }
  (lista->n)++;
}

void suprimeLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  NodoPtr borrar = p->sig;
  p->sig = borrar->sig;
  if (lista->ultimo == borrar) {
    lista->ultimo = p;
  }
  free(borrar);
  (lista->n)--;
}

Simbolo recuperaLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig->dato;
}

PosicionLista buscaLS(Lista lista, char *nombre) {
  NodoPtr aux = lista->cabecera;
  while (aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) != 0) {
    aux = aux->sig;
  }
  return aux;
}

void asignaLS(Lista lista, PosicionLista p, Simbolo s) {
  assert(p != lista->ultimo);
  p->sig->dato = s;
}

int longitudLS(Lista lista) {
  return lista->n;
}

PosicionLista inicioLS(Lista lista) {
  return lista->cabecera;
}

PosicionLista finalLS(Lista lista) {
  return lista->ultimo;
}

PosicionLista siguienteLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig;
}


bool pertenece(char *nombre, Lista lista){		// COMPROBAR SI UN IDENTIFICADOR ESTA EN LA TABLA DE SIMBOLOS
	bool resultado = false;
	if(lista-> n == 0){				// si la lista esta vacia, devuelve false
		resultado = false;;
	}
	else {
		PosicionLista aux = buscaLS(lista, nombre);
		if (aux->sig != NULL){			// si no esta vacia y esta en la tabla de simbolos devuelve true, pertenece
			resultado = true;		// ESTA EN LA TABLA
		}
		else{
			resultado =  false;				// si busca y devuelve null, es decir no esta, devuelve false
		}
	}
	return resultado;
}

void insertaTabla(char *nombre, Lista lista, Tipo tipo){
	Simbolo s;
	s.nombre = strdup(nombre);	
	s.tipo = tipo;
	s.valor = 0;
	
	PosicionLista p = finalLS(lista);
	insertaLS(lista, p, s);
	
}

bool compruebaTipo(char *nombre, Lista lista){
	PosicionLista pos = buscaLS(lista, nombre);
	Simbolo aux = recuperaLS(lista, pos);		
	if (aux.tipo == VARIABLE){
		return true;
	}
	else{
		return false;
	}
}

void imprimeTabla(Lista lista){
	// Recorremos la tabla hasta el final para ir recuperando simbolos e irlos imprimiendo con un formato segun el tipo. Util:
	// inicioLs, finalLs, siguienteLs, recuperaLs
	
	printf("\n###########################\n# Seccion de datos\n	.data\n\n");
	PosicionLista inicio = inicioLS(lista); // este elemento es nulo
	PosicionLista sig = siguienteLS(lista, inicio);	// empezamos desde este elemento
	PosicionLista final = finalLS(lista);
	int n = longitudLS(lista);
	int cont = 1;
	int posicion = 0;
	
	for(int i = 1; i < n+1; i++){		// empezamos desde 1 xq el primer elemento es nulo.
		Tipo aux = sig->dato.tipo;
		if(aux != CADENA){		// si no es una cadena sigue iterando
			if (sig != final) {  // Evitar acceso inválido
           			printf("_%s:\n	.word %d\n", sig->dato.nombre, posicion);	
				sig = siguienteLS(lista, sig);
        		}
        		else{
				printf("_%s:\n	.word %d\n", sig->dato.nombre, posicion);	
        		}
			
		}else{	// si es cadena, empezamos a imprimir
			if (sig != final) {  // Evitar acceso inválido
           			printf("$str%d:\n	.asciiz %s\n", cont++, sig->dato.nombre);
           			sig = siguienteLS(lista, sig);
        		}
        		else{
				printf("$str%d:\n	.asciiz %s\n", cont++, sig->dato.nombre);        	
        		}
		}
	}
}












