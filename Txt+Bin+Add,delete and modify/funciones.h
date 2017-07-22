#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[150];
    float puntaje;
    char linkImagen[500];
}movieStructure;

/*Funciones TP3*/
void addMovie(movieStructure movie, FILE *movieStructureFile,FILE *movieStructureFileHtml);
void deleteMovie(movieStructure movie, FILE *movieStructureFile);
void modifyMovie(movieStructure movie,FILE *movieStructureFile);
void createHtml(movieStructure movie,FILE *movieStructureFile,FILE *movieStructureFileHtml);
void isFileThere (FILE *movieStructureFile,FILE *movieStructureFileHtml);
void menu();

/*Funciones UTN*/ /*Funciones UTN*/ /*Funciones UTN*/ /*Funciones UTN*/ /*Funciones UTN*/ /*Funciones UTN*/ /*Funciones UTN*/
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void clean_stdin(void);
void pause(char message[]);
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

   /*if(auxFeofLastReg!=1)
        {
            if(feof(movieStructureFile))
                break;
        }
        else
        {
            printf("No leyo el ultimo registro");
            break;
        }*/
#endif // FUNCIONES_H_INCLUDED





