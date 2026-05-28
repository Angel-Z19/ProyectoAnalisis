#ifndef MAPA_H
#define MAPA_H

#include "region.h"

#define MAX_REGIONES 50

typedef struct {
    char   nombre[MAX_NOMBRE];
    Region regiones[MAX_REGIONES];
    int    numRegiones;
} Mapa;

/* Inicializa todos los colores a SIN_COLOR */
void inicializarColores(Mapa *mapa);

/* Agrega una relacion de vecindad bidireccional entre dos regiones */
void agregarVecino(Mapa *mapa, int idxA, int idxB);

/* Imprime en consola el resultado del coloreado */
void imprimirResultado(const Mapa *mapa, int numColoresUsados);

#endif /* MAPA_H */
