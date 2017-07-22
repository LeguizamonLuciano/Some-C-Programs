#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define PER_MAX 20

/**\brief Option menu
 * \param int option user inputs an option until it is >5 or <1
 * \return option
 */
int menu()
{
    int option;

    do{
    system("cls");

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    printf("\nSeleccione una opcion: \n");

    scanf("%d", &option);

    }while(option>5||option<1);

    return option;
}

/**\brief Initializes persons' status to 0
 * \param Array data type ePerson.
 */
void intialize(ePerson persons[])
{
    int i;
    for(i = 0; i < PER_MAX; i++)
       persons[i].status = 0;
}

/**\brief Searches for a free place and saves the inputted data as a parameter
 * \param Array data type ePerson.
 */
void addPerson(ePerson persons[])
{
    long dni;
    int index;

    index = freePosition(persons); //Utiliza la funcion fP para buscar un espacio vacio y ahi guardar a la persona

    if(index != -1)
    {
        do{
        printf("\nIngrese DNI: ");
        scanf("%ld", &dni);
        }while(dni<0);

        if(existPerson(persons, dni)) //Si al ingresar un dni la persona ya esta guardada, devuelve el print
        {
            printf("\n!ERROR! La persona ya existPerson.\n");
        }
        else //Si la persona no esta guardada, permite agregarle un name y una edad
        {
            persons[index].status = 1;
            persons[index].dni = dni;

            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(persons[index].name);

            printf("\nIngrese edad: ");
            scanf("%d", &persons[index].edad);

            printf("\nPersona guardada, presione cualquier tecla para continuar operando.\n\n");
        }
    }
    else
    {
        printf("\n!ERROR! No hay espacio disponible, elimine o modifique una persona ya existPersonnte.\n");
    }
}

/** \brief Searches for a persons' DNI, if it's found allows to delete
 *  \param Array data type ePerson.
 */
void deletePerson(ePerson persons[])
{
     long dni;
     int index;
     char answer;

     printf("\nIngrese DNI: ");
     fflush(stdin);
     scanf("%ld", &dni);

     index = existPerson(persons, dni);

     if((index = -1))
     {
         printf("\nDNI [%ld] no encontrado \n\n", dni);
     }
     else //Si encuentra a la persona, muestra sus datos y pide confirmar la eliminacion
     {
        printf("\nDatos de la persona:\n\n");
        printf("DNI:%ld EDAD:%ud name:%s \n", persons[index].dni, persons[index].edad, persons[index].name);
        printf("\nConfirma la eliminacion? [s/S|n] ");
        fflush(stdin);
        scanf("%c", &answer);

        if(answer == 's' || answer == 'S') //Si se confirma, se asiga status 2 a persons[index].status
        {
            persons[index].status = 2;
            printf("\nPersona eliminada exitosamente\n");
        }
        else
        {
            printf("\n\nLa eliminacion fue cancelada...\n\n");
        }
    }
}

/**\brief Persons saved in the array are sorted by name
 * \param Array data type ePerson.
 */
void sortPerson(ePerson persons[])
{
    ePerson auxPerson; //Guarda el dato para no perderlo cuando se hace el ordenamiento
    int i;
    int j;

    for (i = 0; i < PER_MAX - 1; i++)
        for (j = i+1; j < PER_MAX; j++)
            if (strcmp(persons[i].name, persons[j].name)>0) //Si strcmp devuelve mayor a 0, ordena
            {
                auxPerson  = persons[i];
                persons[i] = persons[j];
                persons[j] = auxPerson;
            }
}

/**\brief Prints a list showing:DNI, age and name.
 * \param Array data type ePerson.
 */
void printPerson(ePerson persons[])
{
    int i;

    for(i = 0; i < PER_MAX; i++)
        if(persons[i].status == 1)
            printf("\nDNI:%ld EDAD:%ud name:%s\n", persons[i].dni, persons[i].edad, persons[i].name);

    printf("\n");
}

/**\brief Prints a graph with the following information: Less than 18 * From 19 to 35 * Older than 35
 * \param Array data type ePerson.
 */
void graphPersonAge(ePerson persons[])
{
    int i;
    int cont18 = 0; //Contador para persons menores a 18
    int cont19a35 = 0;//Contador para persons de 19 a 35
    int cont35 = 0;//Contador para persons mayores a 35
    int flag=0;
    int mayor;

    //Doy valores en base a lo ingresado por el usuario a las variables cont18, cont19a35 y cont35.
    for(i=0; i < PER_MAX; i++)
    {
        if(persons[i].status == 1)
        {
            if(persons[i].edad < 19) //Si la edad es menor a 19, suma 1 a la variable cont18
            {
                cont18++;
            }
            else
            {
                if(persons[i].edad > 18 && persons[i].edad < 36) //Si la edad esta entre 19 y 35, suma 1 a la variable cont19a35
                {
                    cont19a35++;
                }
                else
                {
                    cont35++; //Si no se cumplen las 2 condiciones anteriores, suma 1 a la variable cont35++
                }
            }
        }
    }

    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {
        if(cont19a35 >= cont18 && cont19a35 >= cont35)
        {
            mayor = cont19a35;
        }
        else
        {
            mayor = cont35;
        }
    }

    for(i=mayor; i>0; i--)
    {

        if(i <= cont18)
        {
            printf("*");
        }

        if(i <= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }

        printf("\n");
    }

    printf("<18\t19-35\t>35\n");

}

 /**\brief Gets the first available index in the array
 * \param Array data type ePerson.
 * \return First available index.
 */
int freePosition(ePerson persons[])
{
    int index = -1;
    int i;

    for(i = 0; i < PER_MAX; i++)
    {
        if(persons[i].status == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

/**\brief Compares saved DNI with a new one
 * \param Array data type ePerson.
 * \param int dni Searches for the DNI in the array
 * \return If exists returns 1, if not, 0
 */
int existPerson(ePerson persons[], long dni)
{
    int i;
    for(i = 0; i < PER_MAX; i++)
        if(persons[i].dni == dni)
            return 1;

    return 0;
}

