/*******************************************************************
*Programa:  Calculadora
            Trabajo práctico Nº 1
*
*Objetivo:
    Ingresar dos numeros y realizar operaciones de suma,
    resta, multiplicación, división, factorial y todas
    las anteriores en conjunto
*
*Version:0.1 del 04 abril de 2017
*Autor: Luciano Leguizamon
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float x=0; //First number inputted
    float y=0; //Second number inputted
    float z; //Saves the operation result in a variable called 'z'

    char continueMenu='s'; //Condition used on menu's while loop
    while(continueMenu=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",x);
        printf("2- Ingresar 2do operando (B=%f)\n",y);
        printf("3- Calcular la suma (%f+%f)\n",x,y);
        printf("4- Calcular la resta (%f-%f)\n",x,y);
        printf("5- Calcular la division (%f/%f)\n",x,y);
        printf("6- Calcular la multiplicacion (%f*%f)\n",x,y);
        printf("7- Calcular el factorial (%f!)\n",x);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");

        int optionMenu=0; //Expression used for menu selection
        scanf("%d",&optionMenu);

        switch(optionMenu) //Each number represents the desired option in the menu
        {
            case 1:
                printf("\nIngrese primer operando\n");
                scanf("%f",&x);
                printf("Su primer operando es %f \n\n", x);
                break;
            case 2:
                printf("\nIngrese segundo operando\n");
                scanf("%f",&y);
                printf("Su segundo operando es %f \n\n", y);
                break;
            case 3:
                z=addition (x,y);
                printf("\nLa suma entre A=%f y B=%f es: %f\n\n",x,y,z);
                break;
            case 4:
                z=substraction (x,y);
                printf("\nLa resta entre A=%f y B=%f es: %f\n\n",x,y,z);
                break;
            case 5:
                if(y>0)
                {
                    z=quotient (x,y);
                    printf("\nEl cociente entre A=%f y B=%f es: %f\n\n",x,y,z);
                }
                else
                {
                    printf("\nNo es posible dividir por 0\n\n");

                }
                break;
            case 6:
                z=product (x,y);
                printf("El producto entre A=%f y B=%f es: %f\n\n",x,y,z);
                break;
            case 7:
                z=factorial (x);
                printf("El factorial de A=%f es: %f\n\n",x,z);
                break;
            case 8:
                z=addition (x,y);
                printf("\nLa suma entre A=%f y B=%f es: %f\n",x,y,z);
                z=substraction (x,y);
                printf("La resta entre A=%f y B=%f es: %f\n",x,y,z);
                z=quotient (x,y);
                printf("El cociente entre A=%f y B=%f es: %f\n",x,y,z);
                z=product (x,y);
                printf("El producto entre A=%f y B=%f es: %f\n",x,y,z);
                z=factorial (x);
                printf("El factorial de A=%f es: %f\n\n",x,z);
                break;
            case 9:
                continueMenu = 'n';
                break;
        }

    }
 return 0;
}

