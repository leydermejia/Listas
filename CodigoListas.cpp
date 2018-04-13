#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
/*Comentario 
Taller listas
Elaborado por: Fernando Lopez Mejia, Leyder Londoño Mejia */
struct Nodo{
	int dato;
	Nodo *siguiente;
};

void Menu();
void insertarLista(Nodo *&lista,int);
void mostrarLista(Nodo *);
void buscarElemento(Nodo *,int);
void eliminarElemento(Nodo *&lista, int);
void eliminarLista(Nodo *&lista,int);
int main(){
	Menu();
	return 0;	
}
Nodo *lista=NULL;
void Menu(){
	int dato,n;
	int opc =0;
	system("cls");
	
	printf("\n|------------------------------------------------------|");
	printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
	printf("\n|-------------------------|----------------------------|");
	printf("\n|                         |                            |");
	printf("\n| 1. Insertar Lista       | 2. Mostrar Lista           |");
	printf("\n|                         |                            |");
	printf("\n| 3. Buscar Elemento      | 4. Eliminar Elemento       |"); 
	printf("\n|                         |                            |"); 
	printf("\n| 5. Eliminar Lista       | 6 Salir                    |");
	printf("\n|------------------------------------------------------|");
	
	printf("\nOPCION:");
	scanf("\n%d",&opc);
	
	switch(opc){
	case 1:
		printf("Cantidad que desea ingresar a la lista \n");
		scanf("%d",&n);
		printf(" Ingrese los numeros que dese agregar a la lista \n");
		for(int i=0;i<n;i++){
			scanf("%d",&dato);
			insertarLista(lista,dato);
		}
		return Menu();
		
		break;
		
	case 2: mostrarLista(lista);
	printf("\n");
	system("pause");
	return Menu();
	break;
	
	case 3: printf("Ingrese numero que desea buscar de la lista \n");
	        scanf("%d",&dato);
	        buscarElemento(lista,dato);
			printf("\n");
			system("pause");
	        return Menu();
	break;
	
	case 4: printf("Ingrese numero que desea eliminar de la lista \n");
	        scanf("%d",&dato);
	        eliminarElemento(lista,dato);
			printf("\n");
			system("pause");
	        return Menu();
	break;
	
	case 5: 
		    printf(" La Lista se ha eliminado \n");
			while(lista!=NULL){/* Mientras el dato no sea el final de la lista */
				eliminarLista(lista,dato);
			}
			printf("\n");
			system("pause");
			return Menu();
	break;
	
	default: printf("\n\t\tGracias por elegirnos!! \n");
	printf("\n\t\t");
	system("pause");
	break;
	}while(opc!=6);
}
void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	Nodo *aux1=lista;
	Nodo *aux2;
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	printf("dato %d insertado con exito\n",n);
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){
		printf("%d\n",actual->dato);
		actual=actual->siguiente;
	}
}
void buscarElemento(Nodo *lista,int n){
	bool band=false;
	Nodo *actual = new Nodo();
	actual= lista;
	/* Recorrer la lista */
	while((actual != NULL)&&(actual->dato <= n)){
		if(actual-> dato == n){
			band= true;
		}
		actual=actual->siguiente;
	}
	if(band== true){
		printf("El Elemento %d SI a sido encontrado en la lista \n",n);
	}
	else{
		printf("El Elemento %d NO a sido encontrado en la lista \n",n);
	}
}
void eliminarElemento(Nodo *&lista,int n){
	/* Preguntar si la lista esta vacia */
	if(lista !=NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		/* Recorrer la lista */
		while((aux_borrar !=NULL)&&(aux_borrar->dato !=n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		/* El elemento no ha sido encontrado */
		if(aux_borrar == NULL){
			printf(" El Elemento no fue encontrado \n");
		}
		/* Si el primer elemento es el que vamos a eliminar */
		else if(anterior == NULL){
			lista = lista ->siguiente;
			delete aux_borrar;
			printf(" El Elemento fue borrado \n");
		}
		/* Si el elemento esta en la lista pero no es el primer nodo */
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			printf(" El Elemento fue borrado \n");
		}
	}
}
void eliminarLista(Nodo *&lista,int n){
	Nodo *aux=lista;
	n =aux->dato;
	lista= aux->siguiente;
	delete aux;
}
