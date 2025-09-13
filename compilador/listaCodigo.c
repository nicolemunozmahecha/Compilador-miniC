#include "listaCodigo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

char* tn[10] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
int ocupado[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int i = 0;

struct PosicionListaCRep {
  Operacion dato;
  struct PosicionListaCRep *sig;
};

struct ListaCRep {
  PosicionListaC cabecera;
  PosicionListaC ultimo;
  int n;
  char *res;			// CAMPO QUE ASOCIAMOS A CADA LISTA DE CODIGO; x ejemplo, para $t3, $t0, $t1, con recuperares y guardares tendremos almacenados t0 y t1
};

typedef struct PosicionListaCRep *NodoPtr;

ListaC creaLC() {
  ListaC nueva = malloc(sizeof(struct ListaCRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaCRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  nueva->res = NULL;
  return nueva;
}

void liberaLC(ListaC codigo) {
  while (codigo->cabecera != NULL) {
    NodoPtr borrar = codigo->cabecera;
    codigo->cabecera = borrar->sig;
    free(borrar);
  }
  free(codigo);
}

void insertaLC(ListaC codigo, PosicionListaC p, Operacion o) {
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaCRep));
  nuevo->dato = o;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (codigo->ultimo == p) {
    codigo->ultimo = nuevo;
  }
  (codigo->n)++;
}

Operacion recuperaLC(ListaC codigo, PosicionListaC p) {
  assert(p != codigo->ultimo);
  return p->sig->dato;
}

PosicionListaC buscaLC(ListaC codigo, PosicionListaC p, char *clave, Campo campo) {
  NodoPtr aux = p;
  char *info;
  while (aux->sig != NULL) {
    switch (campo) {
      case OPERACION: 
        info = aux->sig->dato.op;
        break;
      case ARGUMENTO1:
        info = aux->sig->dato.arg1;
        break;
      case ARGUMENTO2:
        info = aux->sig->dato.arg2;
        break;
      case RESULTADO:
        info = aux->sig->dato.res;
        break;
    }
    if (info != NULL && !strcmp(info,clave)) break;
	  aux = aux->sig;
  }
  return aux;
}

void asignaLC(ListaC codigo, PosicionListaC p, Operacion o) {
  assert(p != codigo->ultimo);
  p->sig->dato = o;
}

int longitudLC(ListaC codigo) {
  return codigo->n;
}

PosicionListaC inicioLC(ListaC codigo) {
  return codigo->cabecera;
}

PosicionListaC finalLC(ListaC codigo) {
  return codigo->ultimo;
}

void concatenaLC(ListaC codigo1, ListaC codigo2) {
  NodoPtr aux = codigo2->cabecera;
  while (aux->sig != NULL) {
    insertaLC(codigo1,finalLC(codigo1),aux->sig->dato);
    aux = aux->sig;
  }
}

PosicionListaC siguienteLC(ListaC codigo, PosicionListaC p) {
  assert(p != codigo->ultimo);
  return p->sig;
}

void guardaResLC(ListaC codigo, char *res) {
  codigo->res = res;
}

/* Recupera el registro resultado de una lista de codigo */
char * recuperaResLC(ListaC codigo) {
  return codigo->res;
}


char* asignaRes(Operacion *o){
	for (int i = 0; i < 10; i++) {					// recorremos ocupado[i]
		if (ocupado[i] == 0 && tn[i] != NULL) {			// si el temporal no está en uso, asignamos valor a res
		    o->res = tn[i];
		    ocupado[i] = 1;
		    return o->res;
		}
   	}
}

void liberaTemporal(char* res) {
	if (res == NULL) return;  // Evitar accesos inválidos
	for (int i = 0; i < 10; i++) {					// recorremos tn[i]
		if (strcmp(tn[i], res) == 0) {				// comparamos cadenas, si son iguales desocupo la posicion
			ocupado[i] = 0;
		}
	}		
}

char* concatenaCadenas(char* c){
	char aux[11];
	sprintf(aux, "_%s", c);
	return strdup(aux);
}


ListaC asignaId(char *res, char *instr){		
	ListaC lista = creaLC();
	Operacion o;
	o.op = instr;
	o.res = asignaRes(&o);
	guardaResLC(lista, o.res);		
	o.arg1 = concatenaCadenas(res);
	o.arg2 = NULL;
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	return lista;
}

ListaC asignaNum(char *res, char *instr){		
	ListaC lista = creaLC();
	Operacion o;
	o.op = instr;
	o.res = asignaRes(&o);
	guardaResLC(lista, o.res);		
	o.arg1 = res;
	o.arg2 = NULL;
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	return lista;
}

int contadorEtiquetas = 1;

char* nuevaEtiqueta() {
    char* etiqueta = malloc(10);
    sprintf(etiqueta, "$l%d ", contadorEtiquetas);
    return etiqueta;
}


char* nuevaEtiqueta2() {
    char* etiqueta = malloc(10);
    sprintf(etiqueta, "$l%d: ", contadorEtiquetas);
    return etiqueta;
}


ListaC asignacionAritmetica(ListaC res1, ListaC res2, char* instr) {
	ListaC aux = creaLC();
	concatenaLC(aux, res1);			
	concatenaLC(aux, res2);			
	Operacion o;
	o.op = instr;	
	o.res = asignaRes(&o);	
	guardaResLC(aux, o.res);	
	
	o.arg1 = recuperaResLC(res1);
	o.arg2 = recuperaResLC(res2);
	
	liberaTemporal(o.arg1);
	liberaTemporal(o.arg2);
	PosicionListaC p = finalLC(aux);
	insertaLC(aux, p, o);
	return aux;
}


ListaC asignacionInterr(ListaC exp1, ListaC exp2, ListaC exp3){
	ListaC lista = creaLC();
	concatenaLC(lista, exp1);
	
	Operacion o;
	o.op = "\tbeqz";
	o.res = recuperaResLC(exp1);
	o.arg1 = nuevaEtiqueta();
	o.arg2 = NULL;
	
	Operacion o2;
	o2.op = nuevaEtiqueta2();
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	insertaLC(lista, finalLC(lista), o);
	concatenaLC(lista, exp2);
	contadorEtiquetas++;
	
	Operacion o3;
	o3.op = "\tb";
	o3.res = nuevaEtiqueta();
	o3.arg1 = NULL;
	o3.arg2 = NULL;
	
	Operacion move;
	move.op = "\tmove";
	move.res = asignaRes(&move);
	move.arg1 = recuperaResLC(exp2);
	move.arg2 = NULL;
	
	Operacion o4;
	o4.op = nuevaEtiqueta2();
	o4.res = NULL;
	o4.arg1 = NULL;
	o4.arg2 = NULL;
	
	Operacion move2;
	move2.op = "\tmove";
	move2.res = move.res;
	move2.arg1 = recuperaResLC(exp3);
	move2.arg2 = NULL;
	
	insertaLC(lista, finalLC(lista), move);
	insertaLC(lista, finalLC(lista), o3);
	insertaLC(lista, finalLC(lista), o2);
	
	concatenaLC(lista, exp3);
	insertaLC(lista, finalLC(lista), move2);
	insertaLC(lista, finalLC(lista), o4);
	guardaResLC(lista, move.res);
	liberaTemporal(o.res);
	liberaTemporal(move.res);
	liberaLC(exp1);
	liberaLC(exp2);
	liberaLC(exp3);
	contadorEtiquetas++;	
	return lista;

}

void imprimeInstruccion(ListaC instruccion){
	PosicionListaC p2 = inicioLC(instruccion);
	while (p2 != finalLC(instruccion)  ) {
	    Operacion o = recuperaLC(instruccion,p2);
	    printf("%s",o.op);
	    if (o.res) printf("	%s",o.res);
	    if (o.arg1) printf(",   %s",o.arg1);
	    if (o.arg2) printf(",   %s",o.arg2);
	    printf("\n");
	    p2 = siguienteLC(instruccion,p2);
	}
}


ListaC asignaNeg(ListaC res1) {	
	ListaC aux = creaLC();
	concatenaLC(aux, res1);			
	ListaC lista = creaLC();
	Operacion o;
	o.op = "\tneg";	
	o.res = asignaRes(&o);	
	guardaResLC(lista, o.res);	
	
	o.arg1 = recuperaResLC(res1);
	o.arg2 = NULL;
	
	liberaTemporal(o.arg1);
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	concatenaLC(aux, lista);	
	return aux;
}



ListaC asignacion(ListaC res, char* res1) {
	ListaC aux = creaLC();
	concatenaLC(aux, res);
	Operacion o;
	o.op = "\tsw";	
	o.res = recuperaResLC(res);
	guardaResLC(aux, o.res);
	
	o.arg1 = concatenaCadenas(res1);		
	o.arg2 = NULL;
	PosicionListaC p = finalLC(aux);
	insertaLC(aux, p, o);
	liberaTemporal(o.res);
	return aux;
}


ListaC asignaIf(ListaC exp, ListaC stat){
	ListaC lista = creaLC();
	concatenaLC(lista, exp);
	
	Operacion o;
	o.op = "\tbeqz";	
	o.res = recuperaResLC(exp);
	o.arg1 = nuevaEtiqueta();  
	o.arg2 = NULL;
	guardaResLC(lista, o.res); 

	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	liberaLC(exp);
	Operacion o2;
	o2.op = nuevaEtiqueta2(); 
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;

	concatenaLC(lista, stat);
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	
	contadorEtiquetas++;
	liberaTemporal(o.res);
	liberaLC(stat);
	return lista; 
}

ListaC asignaIfElse (ListaC exp, ListaC stat, ListaC stat2){
	ListaC lista = creaLC();
	concatenaLC(lista, exp);
	Operacion o;
	o.op = "\tbeqz";	
	o.res = recuperaResLC(exp);
	o.arg1 = nuevaEtiqueta();  
	o.arg2 = NULL;

	guardaResLC(lista, o.res); 
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	liberaLC(exp);
	
	Operacion o2;
	o2.op = nuevaEtiqueta2(); 
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;

	contadorEtiquetas++;
	
	Operacion o4;
	o4.op = "\tb"; 
	o4.res = nuevaEtiqueta();
	o4.arg1 = NULL;
	o4.arg2 = NULL;
	
	concatenaLC(lista, stat);
	
	PosicionListaC p4 = finalLC(lista);
	insertaLC(lista, p4, o4);

	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	
	Operacion o3;
	o3.op = nuevaEtiqueta2(); 
	o3.res = NULL;
	o3.arg1 = NULL;
	o3.arg2 = NULL;
	
	concatenaLC(lista, stat2);
	PosicionListaC p3 = finalLC(lista);
	insertaLC(lista, p3, o3);
	
	contadorEtiquetas++;
	
	liberaTemporal(o.res);
	liberaLC(stat);
	liberaLC(stat2);
	return lista; 
}

ListaC asignaWhile(ListaC exp, ListaC stat){
	ListaC lista = creaLC();
	
	Operacion o1;
	o1.op = nuevaEtiqueta2(); 
	o1.res = NULL;
	o1.arg1 = NULL;
	o1.arg2 = NULL;
	
	PosicionListaC p1 = finalLC(lista);
	insertaLC(lista, p1, o1);
	
	concatenaLC(lista, exp);
	
	Operacion o4;
	o4.op = "\tb"; 
	o4.res = nuevaEtiqueta();
	o4.arg1 = NULL;
	o4.arg2 = NULL;
	
	contadorEtiquetas++;	
	
	Operacion o;
	o.op = "\tbeqz";	
	o.res = recuperaResLC(exp);
	o.arg1 = nuevaEtiqueta();  
	o.arg2 = NULL;
	
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	concatenaLC(lista, stat);
	
	PosicionListaC p4 = finalLC(lista);
	insertaLC(lista, p4, o4);
	
	Operacion o2;
	o2.op = nuevaEtiqueta2(); 
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	guardaResLC(lista, o.res);
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);

	contadorEtiquetas++;

	liberaLC(exp);
	liberaTemporal(o.res);
	liberaLC(stat);
	return lista; 
	
}

int contadorCad = 1;

char* nuevaCad() {
    char* cadena = malloc(10);
    sprintf(cadena, "$str%d ", contadorCad++);
    return cadena;
}


ListaC asignaPrint(){
	ListaC lista = creaLC();
	
	Operacion o;
	o.op = "\tla";
	o.res = "$a0";
	o.arg1 = nuevaCad();
	o.arg2 = NULL;
	
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	
	Operacion o1;
	o1.op = "\tli";
	o1.res = "$v0";
	o1.arg1 = "4";
	o1.arg2 = NULL;
	
	PosicionListaC p1 = finalLC(lista);
	insertaLC(lista, p1, o1);
	
	Operacion o2;
	o2.op = "\tsyscall";
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	return lista;
}

ListaC asignaPrint2(ListaC exp){
	ListaC lista = creaLC();
	concatenaLC(lista, exp);
	
	Operacion o;
	o.op = "\tmove";
	o.res = "$a0";
	o.arg1 = recuperaResLC(exp);
	o.arg2 = NULL;
	
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	guardaResLC(lista, o.res);
	
	Operacion o1;
	o1.op = "\tli";
	o1.res = "$v0";
	o1.arg1 = "1";
	o1.arg2 = NULL;
	
	PosicionListaC p1 = finalLC(lista);
	insertaLC(lista, p1, o1);
	
	Operacion o2;
	o2.op = "\tsyscall";
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	liberaTemporal(o.arg1);
	return lista;
}

ListaC concatenar(ListaC exp, ListaC exp2){
	ListaC lista = creaLC();
	concatenaLC(lista, exp);
	concatenaLC(lista, exp2);	
	return lista;
}

ListaC asignaIgual(ListaC res){
	ListaC lista = creaLC();
	concatenaLC(lista, res);
	return lista;

}

ListaC asignaRead(char* id){
	ListaC lista = creaLC();
	Operacion o1;
	o1.op = "\tli";
	o1.res = "$v0";
	o1.arg1 = "5";
	o1.arg2 = NULL;
	
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o1);
	
	Operacion o2;
	o2.op = "\tsyscall";
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	
	Operacion o3;
	o3.op = "\tsw";
	o3.res = "$v0";
	o3.arg1 = concatenaCadenas(id);
	o3.arg2 = NULL;
	
	PosicionListaC p3 = finalLC(lista);
	insertaLC(lista, p3, o3);
	return lista;
}



ListaC asignaRead2(ListaC exp, char* id){
	ListaC lista = creaLC();
	ListaC aux = asignaRead(id);
	concatenaLC(exp, aux);
	concatenaLC(lista, exp);
	return lista;
}

ListaC asignaConstList(ListaC const_list, char* id, ListaC exp){
	ListaC aux = asignacion(exp, id);
	liberaLC(exp);
	ListaC lista = creaLC();
	concatenaLC(lista, const_list);
	concatenaLC(lista, aux);
	return lista;
}


ListaC fin(){
	ListaC lista = creaLC();
	Operacion o1;
	o1.op = "\tli";
	o1.res = "$v0";
	o1.arg1 = "10";
	o1.arg2 = NULL;
	
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o1);
	
	Operacion o2;
	o2.op = "\tsyscall";
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;
	
	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2); 
	return lista;
}


void imprimeLista(ListaC exp, ListaC exp1){
	ListaC lista = concatenar(exp, exp1);
	printf("\n###########################\n# Seccion de código\n	.text\n	.globl main\n\nmain:\n");	
	imprimeInstruccion(lista);
	printf("\n###########################\n# Fin\n"); 
	ListaC fin1 = fin();
	imprimeInstruccion(fin1);

}


// MEJORAS
// DO WHILE
ListaC asignaDoWhile(ListaC stat, ListaC exp){
	ListaC lista = creaLC();
	
	Operacion o1;
	o1.op = nuevaEtiqueta2(); 
	o1.res = NULL;
	o1.arg1 = NULL;
	o1.arg2 = NULL;
	
	PosicionListaC p1 = finalLC(lista);
	insertaLC(lista, p1, o1);
	
	concatenaLC(lista, stat);
	concatenaLC(lista, exp);
	
	Operacion o4;
	o4.op = "\tb"; 
	o4.res = nuevaEtiqueta();
	o4.arg1 = NULL;
	o4.arg2 = NULL;
	
	contadorEtiquetas++;	
	
	Operacion o;
	o.op = "\tbeqz";	
	o.res = recuperaResLC(exp);
	o.arg1 = nuevaEtiqueta();  
	o.arg2 = NULL;
	
	guardaResLC(lista, o.res);
	PosicionListaC p = finalLC(lista);
	insertaLC(lista, p, o);
	
	PosicionListaC p4 = finalLC(lista);
	insertaLC(lista, p4, o4);
	
	Operacion o2;
	o2.op = nuevaEtiqueta2(); 
	o2.res = NULL;
	o2.arg1 = NULL;
	o2.arg2 = NULL;

	PosicionListaC p2 = finalLC(lista);
	insertaLC(lista, p2, o2);
	i++;

	contadorEtiquetas++;

	liberaLC(exp);
	liberaTemporal(o.res);
	liberaLC(stat);
	return lista; 
	
}

ListaC asignacionMayorIgual(ListaC exp1, ListaC exp2){
	ListaC aux = asignacionAritmetica(exp1, exp2, "\tslt");  
	ListaC lista = creaLC();

	Operacion o;
	o.op = "\txor"; 
	o.arg1 = recuperaResLC(aux);   
	o.arg2 = "1";            
	o.res = asignaRes(&o);   
	
	guardaResLC(lista, o.res);                
	insertaLC(lista, finalLC(lista), o);      

	concatenaLC(aux, lista);                  
	liberaLC(exp1);
	liberaLC(exp2);

	return aux; 
}



ListaC asignacionIgualIgual(ListaC exp1, ListaC exp2){
	ListaC aux = asignacionAritmetica(exp1, exp2, "\txor");  

	Operacion o;
	o.op = "\tsltiu";
	o.arg1 = recuperaResLC(aux);    
	o.arg2 = "1";    
	o.res = asignaRes(&o);   
	
	guardaResLC(aux, o.res);                
	insertaLC(aux, finalLC(aux), o);      
                 
	liberaLC(exp1);
	liberaLC(exp2);

	return aux; 

}










