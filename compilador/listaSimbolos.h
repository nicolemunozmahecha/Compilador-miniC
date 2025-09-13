#ifndef __LISTA_SIMBOLOS__
#define __LISTA_SIMBOLOS__
#include <stdbool.h>

typedef enum { VARIABLE = 1, CONSTANTE = 2, CADENA = 3 } Tipo; 
typedef struct Nodo {
  char *nombre;
  Tipo tipo;
  int valor;
} Simbolo;
typedef struct ListaRep * Lista;
typedef struct PosicionListaRep *PosicionLista;

Lista creaLS();
void liberaLS(Lista lista);
void insertaLS(Lista lista, PosicionLista p, Simbolo s);
Simbolo recuperaLS(Lista lista, PosicionLista p);
PosicionLista buscaLS(Lista lista, char *nombre);
void asignaLS(Lista lista, PosicionLista p, Simbolo s);
int longitudLS(Lista lista);
PosicionLista inicioLS(Lista lista);
PosicionLista finalLS(Lista lista);
PosicionLista siguienteLS(Lista lista, PosicionLista p);
bool pertenece(char *nombre, Lista lista);
void insertaTabla(char *nombre, Lista lista, Tipo tipo);
bool compruebaTipo(char *nombre, Lista lista);
void imprimeTabla(Lista lista);
#endif
