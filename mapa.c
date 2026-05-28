#include <stdio.h>
#include <string.h>
#include "mapa.h"

/* Nombres de los 8 colores disponibles (indices 0-7) */
static const char *NOMBRES_COLORES[MAX_COLORES] = {
    "rojo", "azul", "verde", "amarillo",
    "naranja", "violeta", "cafe", "rosa"
};

void inicializarColores(Mapa *mapa)
{
    int i;
    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].color = SIN_COLOR;
    }
}

void agregarVecino(Mapa *mapa, int idxA, int idxB)
{
    Region *a = &mapa->regiones[idxA];
    Region *b = &mapa->regiones[idxB];

    /* Evitar duplicados */
    int i;
    for (i = 0; i < a->numVecinos; i++) {
        if (a->vecinos[i] == idxB) return;
    }

    a->vecinos[a->numVecinos++] = idxB;
    b->vecinos[b->numVecinos++] = idxA;
}

void imprimirResultado(const Mapa *mapa, int numColoresUsados)
{
    int i;
    printf("\n=== Resultado: %s ===\n", mapa->nombre);
    printf("Colores minimos necesarios: %d\n\n", numColoresUsados);

    for (i = 0; i < mapa->numRegiones; i++) {
        int c = mapa->regiones[i].color;
        printf("  %-30s -> %s\n",
               mapa->regiones[i].nombre,
               (c >= 0 && c < MAX_COLORES) ? NOMBRES_COLORES[c] : "sin color");
    }
    printf("\n");
}
