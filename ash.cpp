#include <stdio.h>
#include <stdlib.h>
struct lista{
	int valor;
	lista *prox;};
void insertar( lista **Ini, int x){
/* inserta x por el comienzo de la lista p */
	lista *t = new lista;
	t->valor = x;
	t->prox = *Ini;
	*Ini = t;
}
void mostrar ( lista *Ini){
/* muestra por pantalla la lista enlazada */
	lista *t = Ini;
	while ( t){
		printf("[%i]->", t->valor);
		t= t->prox;};
		printf("NULL\n\n");
}
void mostrarlst( lista *p, char c){
/* imprime encabezado y llama a mostrar */
	printf( "\n\n\tLista %c ->",c);
	mostrar( p);
}

int main() {
	int op = -1, x=0, n;
	lista *A=NULL,*B=NULL;
	while ( op ){
		system("cls");
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS \n\n\t ");
		printf( "1.\tInsertar en A\n\t ");
		printf( "2.\tInsertar en B\n\t ");
		printf( "3.\tMostrar listas\n\n\t ");
		printf( "4.\tOrdenamiento\n\n\t ");
		printf( "0.\tSalir\n\n ");
		printf( "\t\tSu opcion (0..3): ");
		scanf("%i", &op);
		switch (op){
			case 1: printf("\n\n\tIndique dato a Insertar en A ");
					scanf( "%i", &x);
					insertar (&A, x);
				break;
			case 2: printf("\n\n\tIndique dato a Insertar en B ");
					scanf( "%i", &x);
					insertar (&B, x);
				break;
			case 3: mostrarlst(A,'A');
					mostrarlst(B,'B');
				break;
		};
		printf("\n\n");
		system("pause");
	}
}
