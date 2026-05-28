#include "backtracking.h"

int esColorValido(const Mapa *mapa, int idx, int color)
{
    const Region *r = &mapa->regiones[idx];
    int i;

    for (i = 0; i < r->numVecinos; i++) {
        if (mapa->regiones[r->vecinos[i]].color == color) {
            return 0; /* conflicto con un vecino */
        }
    }
    return 1;
}

int colorearRecursivo(Mapa *mapa, int idx, int numColores)
{
    /* Caso base: todas las regiones coloreadas */
    if (idx == mapa->numRegiones) {
        return 1;
    }

    int c;
    for (c = 0; c < numColores; c++) {
        if (esColorValido(mapa, idx, c)) {
            mapa->regiones[idx].color = c;

            if (colorearRecursivo(mapa, idx + 1, numColores)) {
                return 1; /* solucion encontrada */
            }

            /* Backtrack */
            mapa->regiones[idx].color = SIN_COLOR;
        }
    }

    return 0; /* ninguna opcion funciono */
}

int encontrarMinimoColores(Mapa *mapa)
{
    int n;

    for (n = 1; n <= MAX_COLORES; n++) {
        inicializarColores(mapa);

        if (colorearRecursivo(mapa, 0, n)) {
            return n; /* minimo encontrado */
        }
    }

    return -1; /* no deberia ocurrir con MAX_COLORES = 8 */
}
