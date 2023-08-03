#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
  #include<windows.h>
#endif  
//Prototipos
int iniciarJuego();
int seleccionarQuienEmpieza();
void inicializarTablero();
void mostrarJuego();
void agregarCasilla();
int verificarRaya();
int verificarCasilla();
void moficarTabla();

//Variable global
char tablero[3][3];

int columnas = 3;
int filas = 3;
int f;
int c;

int cruzCirculo = -1;

int main()
{
    
    int res = 0;
    while(1 == 1)
        {
        system("cls");
        //Se inicia el tablero
        inicializarTablero();
        //Se pregunta si desea jugar
        if(iniciarJuego() == 2)
        {
            break;
        }
        system("cls");

        //Se selecciona cual ficha empieza a jugar
        seleccionarQuienEmpieza();

        system("cls");
        agregarCasilla();
        system("cls");
        //Se hace el 1juego
        while (1 == 1)
        {
            system("cls");
            mostrarJuego();
            agregarCasilla();
            
            res = verificarRaya();
            if(c == 0 || f == 0)
            {
                break;
            }
            if(res > 0)
            {
                system("cls");
                if(res == 1)
                {
                    printf("Gano el circulo");
                }
                else
                {
                    printf("Gano la cruz");
                }
                printf("\n");
                mostrarJuego();

                printf("\n Pulse una tecla para continuar...\n");
                getch();
                break;
            }
        }
    }
    return 0;
}

int iniciarJuego()
{
    int res = 0;
    while (res < 1 || res > 2)
    {
        printf("1 - Si\n2 - No\nDesea jugar: ");
        scanf(" %d", &res);
    }
    return res;
}
int seleccionarQuienEmpieza() //Selecciona si empieza cruz (X) o circulo (O)
{
    while(cruzCirculo < 0 || cruzCirculo > 1)
    {
        printf("0 - Cruz\n1 - Circulo\nIngrese quien empieza: ");
        scanf(" %d", &cruzCirculo);
    }
}

//Inicializa todas las celdas de la matriz
void inicializarTablero()
{
    for(int i = 0; i < columnas; i++)
    {
        for(int j = 0; j < filas; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

//Se muestra la matriz
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
    //Se le asigna el valor 0 a las variables
    while(1 == 1)
        {
        f = -1;
        c = -1;
        printf("\n");
        //Se ingresa la fila
        while (f < 0 || f > 3)
        {
            printf("Ingrese la fila seleccionada: ");
            scanf(" %d", &f);
        }
        
        if(f == 0)
        {
            break;
        }
        
        //Se ingresa la columna
        while (c < 0 || c > 3)
        {
            printf("Ingrese la columna seleccionada: ");
            scanf(" %d", &c);
        }
        
        if(c == 0)
        {
            break;
        }
        if(verificarCasilla(c, f) == 1)
        {
            break;
        }
    }
    moficarTabla();
}

//Se modifica la celda en cuestion;
void moficarTabla()
{
    if(cruzCirculo % 2 == 0)
    {
        tablero[c-1][f-1] = 'X';
    }
    else
    {
        tablero[c-1][f-1] = 'O';
    }
    cruzCirculo++;
}

/*
    Verifica si una casilla esta ocupada o no
        Devuelve 1 si no esta ocupada
        Devuelve -1 si esta ocupada
*/
int verificarCasilla(int columna, int fila)
{
    if(columna > 3 || columna < 1 || fila > 3 || fila < 1)
    {
        return -1;
    }
    if(tablero[columna-1][fila-1] == ' ')
    {
        //printf("\nEs una columna permitida\n");
        return 1;
    }
    //printf("\nNo es una columna permitida\n");
    return -1;
}

/*Verifica si hay alguna raya formada
    Si tiene una raya, va a devolver 1
    Si no tiene una raya, va a devolver -1
*/
int verificarRaya()
{
    int hayRaya = -1;
    //Se verifican las columnas, filas y diagonales
    for(int i = 0; i < columnas; i++)
    {
        if(tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[1][i] != ' ')
        {
            if(tablero[1][i] == 'x')
            {
                hayRaya = 2;
            }
            else
            {
                hayRaya = 1;    
            }
            
        }
        else if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ')
        {
            if(tablero[i][0] == 'x')
            {
                hayRaya = 2;
            }
            else
            {
                hayRaya = 1;    
            }
        }
        else if(tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[1][1] != ' ')
        {
            if(tablero[0][0] == 'x')
            {
                hayRaya = 2;
            }
            else
            {
                hayRaya = 1;    
            }
        }
        else if(tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2] && tablero[2][0] != ' ')
        {
            if(tablero[2][0] == 'x')
            {
                hayRaya = 2;
            }
            else
            {
                hayRaya = 1;    
            }
        }
        
    }
    
    return hayRaya;
}
