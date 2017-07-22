/*******************************************************************
*Programa:   Estructura que represente una persona, con los campos name, edad, dni y un
             flag de status.
             Trabajo práctico Nº 2
*
*Objetivo:   Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú
*
*
*Version:0.1 del 28 abril de 2017
*Autor: Luciano Leguizamon
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define PER_MAX 20 //Maxima cantidad de persons a ser agregadas

int main()
{
    ePerson persons[PER_MAX];
    intialize(persons);

    int loop = 1;
    do
    {
        switch(menu())
        {
            case 1:
                {
                    addPerson(persons);
                    system("pause");
                    break;
                }
            case 2:
                {
                    deletePerson(persons);
                    system("pause");
                    break;
                }
            case 3:
                {
                    sortPerson(persons);
                    printPerson(persons);
                    system("pause");
                    break;
                }
            case 4:
                {
                    graphPersonAge(persons);
                    system("pause");
                    break;
                }
            case 5:
                {
                    loop = 0;
                    break;
                }
        }
    }while(loop == 1); //Ejecuta 1 vez el menu y sale del while cuando loop sea distinto de 1

    return 0;
}
