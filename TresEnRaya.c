#include <stdio.h>
#include <conio.h>

//Prototipos
int seleccionarQuienEmpieza();
void inicializarTablero();
void mostrarJuego();
void agregarCasilla();
int verificarRaya();
int verificarCasilla();
void moficarTabla();

//Variable global
int tablero[3][3];

int columnas = 3;
int filas = 3;
int f;
int c;

int cruzCirculo = -1;

int main()
{
    inicializarTablero();
    while(1 == 1)
    {
        agregarCasilla();

    }
    /*
    seleccionarQuienEmpieza();
    agregarCasilla();
    while (verificarRaya() != 0)
    {
        mostrarJuego();
        agregarCasilla();
    }
    */
    return 0;
}

int seleccionarQuienEmpieza() //Selecciona si empieza cruz (X) o circulo (O)
{
    while(cruzCirculo < 0 || cruzCirculo > 1)
    {
        printf("0 - Circulo\n1 - Cruz\nIngrese quien empieza");
        scanf(" %d", &cruzCirculo);
    }
}
void inicializarTablero()
{
    for(int i = 0; i < columnas; i++)
    {
        for(int j = 0; j < filas; j++)
        {
            tablero[i][j] = -1;
        }
    }
}

void mostrarJuego()
{
    printf("Se muestra el juego\n");
    for(int i = 0; i < columnas; i++)
    {
        printf(" | ");
        for(int j = 0; j < filas; j++)
        {
            printf("%c | ", tablero[i][j]);
        }
        printf("\n");
    }
}

//Permite ingresar una casilla
void agregarCasilla()
{
    
    
    
    while(1 == 1)
    {
        //Se le asigna el valor 0 a las variables
        f = 0;
        c = 0;

        //Se ingresa la fila
        while (f < 1 || f > 3)
        {
            printf("Ingrese la fila seleccionada: ");
            scanf(" %d", &f);
        }

        //Se ingresa la columna
        while (c < 1 || c > 3)
        {
            printf("Ingrese la columna seleccionada: ");
            scanf(" %d", &c);
        }
        if(verificarCasilla(c, f) == 1)
        {
            break;
        }
    }
    moficarTabla();
}


void moficarTabla()
{
    tablero[c-1][f-1] = cruzCirculo % 2;
    cruzCirculo++;
}

int verificarCasilla(int columna, int fila)
{
    if(columna > 3 || columna < 1 || fila > 3 || fila < 1)
    {
        return -1;
    }
    if(tablero[columna-1][fila-1] == 0)
    {
        printf("\nEs una columna permitida\n");
        return 1;
    }
    printf("\nNo es una columna permitida\n");
    return -1;
}

//Verifica si hay alguna raya formada
int verificarRaya()
{
    return 1;
}