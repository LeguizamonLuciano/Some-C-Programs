#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    long dni; //Los DNI se pasan de 32767
    char name[50];
    unsigned int edad; //No hay edades negativas
    int status;
}ePerson;

int menu();

void intialize(ePerson[]);
void addPerson(ePerson persons[]);
void deletePerson(ePerson persons[]);
void sortPerson(ePerson persons[]);
void printPerson(ePerson otraspersons[]);
void graphPersonAge(ePerson persons[]);


int existPerson(ePerson persons[], long dni);

int freePosition(ePerson[]);

#endif // FUNCIONES_H_INCLUDED
