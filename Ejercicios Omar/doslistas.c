#include <stdio.h>
#include <stdlib.h>
#define true 1 
#define false 0 

typedef struct lista {
    int valor;
    struct lista *sig;
} lista; 

void insertar( lista **cab, int x){
	/* inserta x por el comienzo de la lista p */
	lista *t;
	t= malloc(sizeof(lista));
	t->valor = x;
	t->sig  = *cab;
	*cab = t;
}

void eliminar ( lista **p, int x){
	/* elimina la primera ocurrencia del valor x en la lista p */
	lista *t=*p;
	if (t)
	   if (t->valor==x){
	   	   *p=(*p)->sig;
	   	   free( t);
	   }
	   else {
	   	   while ((t->sig)&&(t->sig->valor != x)) t=t->sig;
	   	   if (t->sig){
	   	   	   lista *aux= t->sig;
	   	   	   t->sig = t->sig->sig;
	   	   	   free( aux );
			  }
	   }
}

void mostrar ( lista *cab){
	/* muestra por pantalla la lista enlazada */
	lista *t = cab;
	//agregar system("cls"); 
	printf( "\n\nMostrar lista\n\n  Cab ");
	while (t){
		printf("->[%i]", t->valor);
		t= t->sig;
	}
	printf("->NULL\n\n");
}

void intercalarCasillas(lista **cabb, lista **caba){
	lista *auxA = *caba, *auxB = *cabb, *previo;
	
	if(!cabb){
		*cabb= *caba;
		*caba = NULL;
	}

	while (auxA && auxB) {
		*caba=(*caba)->sig;
		previo=auxA;
		auxA->sig = auxB->sig;
		auxB->sig = auxA;
		auxB = auxA->sig;
		auxA=*caba;
	}

	if(!auxB && auxA) {
		previo->sig=*caba;
		*caba=NULL;
	}
}

void main () {
    int op = -1, x=0, y=0;
	lista *a=NULL, *b=NULL;
	while ( op ){
        
        printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n");
        printf( "1.\tInsertar numero en lista a\n\n");
        printf( "2.\tInsertar numero en lista b\n\n");
        printf( "3.\tEliminar numero en lista a\n\n");
        printf( "4.\tEliminar numero en lista b\n\n");
        printf( "5.\tMostrar lista a\n\n");
        printf( "6.\tMostrar lista b\n\n");
		printf( "7.\tIntercalar listas\n\n");
		printf( "0.\tSALIR del sistema\n\n ");
        scanf("%i", &op);
		
		switch (op){
		case 1: printf("\n\nIndique dato a Insertar\n");
		        scanf( "%i", &x);
		        insertar (&a, x);
		        break;
        case 2: printf("\n\nIndique dato a Insertar \n");
		        scanf( "%i", &x);
		        insertar (&b, x);
		        break;
        case 3: printf("\n\nIndique dato a eliminar \n");
		        scanf( "%i", &x);
		        eliminar (&a, x);
		        break;
        case 4: printf("\n\nIndique dato a eliminar\n ");
		        scanf( "%i", &x);
		        eliminar (&b, x);
		        break;
        case 5: printf("Lista a es => ");
		        mostrar(a);
		        break;
        case 6: printf("Lista b es => ");
		        mostrar(b);
		        break;
		case 7: intercalarCasillas(&b,&a);
		        break;
        }
    }
}