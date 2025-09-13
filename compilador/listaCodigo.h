#ifndef __LISTA_CODIGO__
#define __LISTA_CODIGO__

typedef enum { OPERACION, ARGUMENTO1, ARGUMENTO2, RESULTADO } Campo;

/* Una operación MIPS tiene, en el caso más complejo:
- op: código de operación, como "add", "mv", etc.
- arg1: argumento 1 de la operación, como "$t0", etc.
- arg2: argumento 2 de la operación, como "$t1", etc.
- res: resultado de la operación, como "$t3", etc.
Si algún campo no se usa, se marca con NULL.
*/
typedef struct {
	char * op;
	char * res;
	char * arg1;
	char * arg2;
} Operacion;

/* ListaC es una lista enlazada de código, que contiene instancias de Operacion */
typedef struct ListaCRep * ListaC;
typedef struct PosicionListaCRep *PosicionListaC;

/* Crea una lista de código */
ListaC creaLC();
/* Destruye una lista de código */
void liberaLC(ListaC codigo);
/* Inserta una nueva operación en la lista de código, en la posición indicada */
void insertaLC(ListaC codigo, PosicionListaC p, Operacion o);
/* Recupera la operación que ocupa la posición indicada */
Operacion recuperaLC(ListaC codigo, PosicionListaC p);
/* Busca una operación en la lista, a partir de cierta posición, con un valor en cierto campo */
PosicionListaC buscaLC(ListaC codigo, PosicionListaC p, char *clave, Campo campo);
/* Asigna una operación a cierta posición de la lista */
void asignaLC(ListaC codigo, PosicionListaC p, Operacion o);
/* Concatena dos listas de código. La primera lista se modifica para formar el resultado */
void concatenaLC(ListaC codigo1, ListaC codigo2);
/* Longitud de una lista de código */
int longitudLC(ListaC codigo);
/* Posición de comienzo de una lista de código */
PosicionListaC inicioLC(ListaC codigo);
/* Posición de final de una lista de código */
PosicionListaC finalLC(ListaC codigo);
/* Posición siguiente de una dada en una lista de código */
PosicionListaC siguienteLC(ListaC codigo, PosicionListaC p);
/* Almacena el registro resultado de una lista de código */
void guardaResLC(ListaC codigo, char *res);
/* Recupera el registro resultado de una lista de código */
char * recuperaResLC(ListaC codigo);

ListaC asignaId(char *res, char *instr);
ListaC asignaNum(char *res, char *instr);
ListaC asignacionAritmetica(ListaC res1, ListaC res2, char* instr);
ListaC asignacionInterr(ListaC exp1, ListaC exp2, ListaC exp3);
ListaC asignaIgual(ListaC res);
ListaC asignaNeg(ListaC res);
ListaC asignacion(ListaC res, char* res1);

char* asignaRes(Operacion *o);
void liberaTemporal(char* res);
void imprimeInstruccion(ListaC instruccion);
char* concatenaCadenas(char* c);
char* nuevaEtiqueta();
char* nuevaEtiqueta2();
char* nuevaCad();

ListaC concatenar(ListaC exp, ListaC exp1);
ListaC asignaIf(ListaC exp, ListaC stat);
ListaC asignaIfElse(ListaC exp, ListaC stat, ListaC stat2);
ListaC asignaWhile(ListaC exp, ListaC stat);
ListaC asignaPrint();
ListaC asignaPrint2(ListaC exp);
ListaC asignaRead(char* id);
ListaC asignaRead2(ListaC exp, char*id);
ListaC asignaConstList(ListaC const_list, char* id, ListaC exp);
ListaC fin();

void imprimeLista(ListaC exp, ListaC exp1);

ListaC asignaDoWhile(ListaC stat, ListaC exp);
ListaC asignacionMayorIgual(ListaC exp1, ListaC exp2);
ListaC asignacionIgualIgual(ListaC exp1, ListaC exp2);


#endif
