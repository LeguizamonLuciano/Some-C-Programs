#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char menuLoop='s';
    int option=0;

    movieStructure movie;
    FILE *movieStructureFile;
    FILE *movieStructureFileHtml;

    movieStructureFile = fopen("movieBin.dat","rb+");
    movieStructureFileHtml=fopen("movieStructureFileHtml.html","r+");/*Abro el archivo para lectura|escritura*/

    isFileThere(movieStructureFile,movieStructureFileHtml); /*Si no existe crea el archivo*/

    while(menuLoop=='s')
    {
        menu(); /*Genero el menu*/

        scanf("%d",&option);
        switch(option)
        {
            case 1:
                addMovie(movie,movieStructureFile,movieStructureFileHtml);
                break;
            case 2:
                deleteMovie(movie,movieStructureFile);
                break;
            case 3:
                modifyMovie(movie,movieStructureFile);
                break;
            case 4:
                createHtml(movie,movieStructureFile,movieStructureFileHtml);
                break;
            case 5:
                menuLoop = 'n';
                break;
        }
    }
    return 0;
}
