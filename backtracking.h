#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "mapa.h"

/*
 * Verifica si 'color' puede asignarse a la region 'idx'
 * sin conflicto con sus vecinos ya coloreados.
 * Retorna 1 si es valido, 0 si no.
 */
int esColorValido(const Mapa *mapa, int idx, int color);

/*
 * Intenta colorear el mapa usando exactamente 'numColores' colores
 * mediante backtracking recursivo.
 * Retorna 1 si encontro solucion, 0 si no es posible con esa cantidad.
 */
int colorearRecursivo(Mapa *mapa, int idx, int numColores);

/*
 * Funcion principal: encuentra el numero minimo de colores necesarios.
 * Prueba desde 1 hasta MAX_COLORES hasta encontrar solucion.
 * Retorna el numero minimo de colores, o -1 si no hay solucion.
 */
int encontrarMinimoColores(Mapa *mapa);

#endif /* BACKTRACKING_H */
