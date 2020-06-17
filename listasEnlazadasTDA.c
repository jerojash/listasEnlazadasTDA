#include<stdio.h>
#include<stdlib.h>

struct pila{
	int x;
	struct pila *prox;
};

int insertar(){
	int num;
	printf("Ingrese un numero para apilar\n");
	scanf("%i",&num);
	return num;
}

int mostrar(struct pila *aux){
	if(aux){
		printf("[%i]-->",aux->x);
		aux=aux->prox;
		mostrar(aux);
	}else printf("[FONDO]\n");
	
	return 0;
	
}

/*---------------------------OPERACIONES DE TDA---------------------------*/

void apilar(struct pila **p){
	struct pila *aux=malloc(sizeof(struct pila));
	aux->x=insertar();
	aux->prox=*p;
	*p=aux;
	
};

int vacio(struct pila *p){

	return (p==NULL);
};

void desapilar(struct pila **p){
	
	if (!vacio(*p)){
		
		struct pila *aux=*p;
		*p=(*p)->prox;
		free(aux);
		
	}else printf("La operacion es invalida, su pila esta vacia\n");
}

void tope(struct pila *p){
	
	if (vacio(p)){
		printf("El tope de la pila es [NULL]\n");
	}else printf("El tope de la pila es [%i]\n",p->x);
	
}

/*---------------------------FIN DE LAS OPERACIONES DE TDA---------------------------*/

int main(){
	int menu=1;
	struct pila *p;
	p=NULL;
	while(menu){
		printf("\n\n		MENU BASE DE PILA:\n\n");
		printf("		(1)MOSTRAR PILA\n");
		printf("		(2)APILAR\n");
		printf("		(3)DESAPILAR\n");
		printf("		(4)MOSTRAR TOPE DE LA PILA\n");
		printf("		(0)SALIR\n\n\n");
	
		scanf("%i",&menu);
		switch (menu){
			case 1: printf("[TOPE]-->");
					mostrar(p);
					system("pause");		
				break;
			case 2: apilar(&p);
				break;
			case 3: desapilar(&p);
					system("pause");
				break;
			case 4: tope(p);
					system("pause");
				break;
		}
		system("cls");	
	
	}
		return 0;
}
