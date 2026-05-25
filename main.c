#include <stdio.h>
#include <string.h>

#define MAX_REGIONES 20
#define MAX_VECINOS 20
#define MAX_COLORES 8

typedef struct {
    char nombre[50];
    int vecinos[MAX_VECINOS];
    int numVecinos;
    int color;
} Region;

typedef struct {
    char nombre[50];
    Region regiones[MAX_REGIONES];
    int numRegiones;
} Mapa;

/* Funciones generales */
void agregarVecino(Mapa *mapa, int origen, int destino);
int esColorValido(Mapa *mapa, int regionActual, int color);
int colorearBacktracking(Mapa *mapa, int regionActual, int maxColores);

/* main */
int main() {
    // Aquí después vamos a crear el mapa y llamar las funciones
    return 0;
}

/* Implementación de funciones */
void agregarVecino(Mapa *mapa, int origen, int destino) {
    mapa->regiones[origen].vecinos[mapa->regiones[origen].numVecinos] = destino;
    mapa->regiones[origen].numVecinos++;

    mapa->regiones[destino].vecinos[mapa->regiones[destino].numVecinos] = origen;
    mapa->regiones[destino].numVecinos++;
}

int esColorValido(Mapa *mapa, int regionActual, int color) {
    for (int i = 0; i < mapa->regiones[regionActual].numVecinos; i++) {
        int vecino = mapa->regiones[regionActual].vecinos[i];

        if (mapa->regiones[vecino].color == color) {
            return 0;
        }
    }

    return 1;
}

int colorearBacktracking(Mapa *mapa, int regionActual, int maxColores) {
    if (regionActual == mapa->numRegiones) {
        return 1;
    }

    for (int color = 0; color < maxColores; color++) {
        if (esColorValido(mapa, regionActual, color)) {
            mapa->regiones[regionActual].color = color;

            if (colorearBacktracking(mapa, regionActual + 1, maxColores)) {
                return 1;
            }

            mapa->regiones[regionActual].color = -1;
        }
    }

    return 0;
}