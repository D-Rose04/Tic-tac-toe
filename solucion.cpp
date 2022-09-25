#include "constantes.h"
#include "solucion.h"
#include "logica.h"

#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de
    dos dimensiones tablero.

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna
    de la siguiente manera:
    tablero[1][0]
    */
    char **tablero = GetTablero();
    int filledRows = 0;
    // Comprobacion en horizontal y vertical del ganador
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == 'X' && tablero[i][1] == 'X' && tablero[i][2] == 'X')
        {
            return GANO_X;
        }

        if (tablero[0][i] == 'X' && tablero[1][i] == 'X' && tablero[2][i] == 'X')
        {
            return GANO_X;
        }

        if (tablero[i][0] == 'O' && tablero[i][1] == 'O' && tablero[i][2] == 'O')
        {
            return GANO_O;
        }

        if (tablero[0][i] == 'O' && tablero[1][i] == 'O' && tablero[2][i] == 'O')
        {
            return GANO_O;
        }

        // Comprabacion de empate
        if (tablero[i][0] != '_' && tablero[i][1] != '_' && tablero[i][2] != '_')
        {
            filledRows++;
        }
    }

    // Comprobacion en diagonal
    if (tablero[1][1] == 'X' && tablero[0][0] == 'X' && tablero[2][2] == 'X')
    {
        return GANO_X;
    }

    if (tablero[1][1] == 'X' && tablero[0][2] == 'X' && tablero[2][0] == 'X')
    {
        return GANO_X;
    }

    if (tablero[1][1] == 'O' && tablero[0][0] == 'O' && tablero[2][2] == 'O')
    {
        return GANO_O;
    }

    if (tablero[1][1] == 'O' && tablero[0][2] == 'O' && tablero[2][0] == 'O')
    {
        return GANO_O;
    }

    if (filledRows == 3)
    {
        return EMPATE;
    }

    return JUEGO_EN_CURSO;
}
