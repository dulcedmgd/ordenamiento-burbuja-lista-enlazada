#include <iostream>
#include <string.h>

using namespace std;

struct Nodo{
	int valor;
	Nodo *sucesor;	
};

Nodo* insertar(Nodo **cabecera);
void imprimirLista(Nodo **cabecera, char titulo[50]);
void ordenarListaBurbuja(Nodo **cabecera);

int main(int argc, char** argv) {
	Nodo *cabecera = NULL, *actual = NULL;
	char resp, titulo[50];
	
	actual = insertar(&cabecera);
	cout << endl << "Desea ingresar un nuevo valor en la lista? Y/N ";
	cin >> resp;
	
	while(resp == 'y' || resp == 'Y'){		
		actual = insertar(&actual);
		cout << endl << "Desea ingresar un nuevo valor en la lista? Y/N ";
		cin >> resp;
	}
	
	strcpy(titulo, "Lista de entrada"); // asigna el nombre de la primera lista a mostrar: lista de entrada
	imprimirLista(&cabecera, titulo);
	ordenarLista(&cabecera);	
	
	strcpy(titulo, "Lista ordenada"); // asigna el nombre de la primera lista a mostrar: lista inicial
	imprimirLista(&cabecera, titulo);
	return 0;
}

Nodo* insertar(Nodo **cabecera){
	Nodo *nuevo, *antes;
	
	nuevo = new Nodo;
	if(nuevo){
		cout << endl << "Ingrese el nuevo valor para ingresar a la lista: ";
		cin >> nuevo->valor;
		
		if(*cabecera == NULL){ //lista vacia, insertamos el primer valor
			nuevo->sucesor = NULL;
			*cabecera = nuevo;
		}else{ //lista no vacia, insertamos un nuevo valor
			antes = *cabecera;
			nuevo->sucesor = NULL;
			antes->sucesor = nuevo;
			*cabecera = antes;
		}
	}else{
		cout << "No hay memoria";
	}
	return nuevo;
}

void imprimirLista(Nodo **cabecera, char titulo[50]){
	Nodo *actual = *cabecera;
	
	cout << endl << endl << " ** "<< titulo <<" ** " << endl;
	while(actual->sucesor != NULL){
		cout << actual->valor << " ";
		actual = actual->sucesor;
		if(actual->sucesor == NULL){
				cout << actual->valor << " ";
		}
	}
}

void ordenarListaBurbuja(Nodo **cabecera){
     Nodo *actual , *sucesor;
     int valor;
     
     actual = *cabecera;
     
     while(actual->sucesor != NULL){
          sucesor = actual->sucesor;          
          while(sucesor != NULL){
               if(actual->valor > sucesor->valor){
                    valor = sucesor->valor;
                    sucesor->valor = actual->valor;
                    actual->valor = valor;          
               }
               sucesor = sucesor->sucesor;                    
          }    
          actual = actual->sucesor;
          sucesor = actual->sucesor;
           
     }
}
