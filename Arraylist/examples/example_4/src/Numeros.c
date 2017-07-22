#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../inc/ArrayList.h"
#include "../inc/FuncionesValidacion.h"
#include "../inc/Numeros.h"

void ingresarNumeros(ArrayList* pList)
{
	char resp = 's';
	int* element;
	element = (int*) malloc(sizeof(int));

	do
	{
		*element = pedirNumero("Ingrese un numero: ");
		pList -> add(pList, element);

		resp = preguntarSiSeguir("Desea continuar?s/n: ");
		resp = tolower(resp);

	}while(resp != 'n');
}

//funcion para CLEAR()
void borrarElementosLista(ArrayList* pList)
{
		char resp = 's';

	resp = preguntarSiSeguir("\nSeguro que desea borrar por completo la lista?s/n: ");
	resp = tolower(resp);

	if(resp == 's')
	{
		if(pList -> size > 0)
		{
			pList -> clear(pList);
		}
		else
			printf("\nNo existe una lista a borrar\n");

	}
}


//funcion para REMOVE()
void eliminarElemento(ArrayList* pList)
{
	int i;
	char resp;

	do
	{

		resp = 'n';

		i = pedirNumero("Ingrese la posicion en la lista que desea borrar: ");

		i--;

		if(longitudLista(pList, i) == 0)
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			pList -> remove(pList, i);
			printf("\nPosicion borrada");

		}


		resp = tolower(resp);

	}while(resp != 'n');



	system("PAUSE");

}


//funcion para SET()
void ingresarElementoEnIndice(ArrayList* pList)
{
	int i;
	char resp;
	int* numero;

	do
	{
		resp = 'n';

		i = pedirNumero("Ingrese la posicion de la lista que desea insertar: ");

		i--;

		if(!longitudLista(pList, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			numero = (int*) malloc(sizeof(int));

			*numero = pedirNumero("Ingrese un numero a la posicion: ");

			pList->set(pList, i, numero);

			printf("\nValor agregado con exito\n");

		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");
}

//funcion para get
void retornaElemento(ArrayList* pList)
{
	int i;
	char resp;

	do
	{
		resp = 'n';

		i = pedirNumero("Ingrese la posicion de la lista que desea obtener: ");

		i--;

		if(!longitudLista(pList, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{

			printf("\nEl conenido de la posicion [%d] es: %d\n", i+1 , *(int*)(pList->get(pList, i)));


		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");
}

//funcion para push()
//inserta elemento en la lista
void insertaElemento(ArrayList* pList)
{

	int i;
	char resp;
	int* numero;



	do
	{
		resp = 'n';

		i = pedirNumero("Ingrese la posicion de la lista que desea insertar: ");

		i--;

		if(!longitudLista(pList, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{
			numero = (int*) malloc(sizeof(int));

			*numero = pedirNumero("Ingrese un numero a la posicion: ");


			pList->push(pList, i, numero);

			printf("\nElemento agregado con exito\n");

		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");

}


//funcion para pop()
void muestraElimina(ArrayList* pList)
{
	int i;
	char resp;

	do
	{
		resp = 'n';

		i = pedirNumero("Ingrese la posicion de la lista que desea obtener: ");

		i--;

		if(!longitudLista(pList, i))
			resp = preguntarSiSeguir("\nLa posicion no existe\nDesea volver a intentarlo?s/n: ");
		else
		{

			printf("\nEl conenido de la posicion [%d] es: %d\n", i+1 , *(int*)(pList->pop(pList, i)));
			printf("\nHa sido eliminada\n");

		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");
}


//funcion para indexof()
void muestraIndice(ArrayList* pList)
{
	int* numero;
	char resp;


	do
	{
		resp = 'n';

		numero = (int*) malloc(sizeof(int));

		*numero = pedirNumero("Ingrese un numero para buscar en la lista: ");

		if(pList->indexOf(pList, numero) == -1)
		{
			printf("\nEl numero ingresado no se encuentra en la lista\n");

			resp = preguntarSiSeguir("\nDesea volver a intentarlo?s/n: ");
		}

		else
		{

			printf("\nEl valor ingresado se encuentra primero en el indice [%d]\n", pList->indexOf(pList, numero) + 1);

		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");

}


//funcion size()
void muestraTamanioLista(ArrayList* pList)
{
	printf("El tamanio de la lista es: %d\n", pList->size);

	system("PAUSE");
	system("cls");
}


//funcion contains()
void compruebaElemento(ArrayList* pList)
{
	int* numero;
	char resp;


	do
	{
		resp = 'n';

		numero = (int*) malloc(sizeof(int));

		*numero = pedirNumero("Ingrese un numero para buscar en la lista: ");

		if(!pList->contains(pList, numero))
		{
			printf("\nEl numero ingresado no se encuentra en la lista\n");

			resp = preguntarSiSeguir("\nDesea volver a intentarlo?s/n: ");
		}

		else
		{

			printf("\nEl valor ingresado se encuentra en la lista %d\n", pList->contains(pList, numero) + 1);

		}
		resp = tolower(resp);

	}while(resp != 'n');





	system("PAUSE");

}

//funcion isEmpty()
void listaVacia(ArrayList* pList)
{
	if(!pList -> isEmpty(pList))
		printf("\nNo hay elementos en la lista\n");
	else
		printf("\nLa lista contiene elementos");
}


void mostrar(ArrayList* pList)
{
	int i;

	if(pList -> size > 0)
	{
		printf("POSICIONES\tVALORES\n");

		for(i = 0; i < pList->size ; i++)
		{
			printf("[%d]\t\t%d\n", i+1 , *(int*)(pList->pElements[i]));
		}

	}
	else
		printf("\nDebe ingresar por lo menos un elemento a la lista\n");

	system("PAUSE");
	system("cls");

}
