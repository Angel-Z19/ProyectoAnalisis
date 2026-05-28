#include <string.h>
#include "espana.h"

/*
 * Espana - 12 comunidades autonomas peninsulares:
 * 0-Galicia,        1-Asturias,     2-Cantabria,    3-PaisVasco,
 * 4-Navarra,        5-Aragon,       6-Cataluna,     7-CastillaYLeon,
 * 8-LaRioja,        9-Madrid,       10-Extremadura, 11-Andalucia
 */
void cargarEspana(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Espana", MAX_NOMBRE);
    mapa->numRegiones = 12;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color      = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre,  "Galicia",        MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre,  "Asturias",       MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre,  "Cantabria",      MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre,  "PaisVasco",      MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre,  "Navarra",        MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre,  "Aragon",         MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre,  "Cataluna",       MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre,  "CastillaYLeon",  MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre,  "LaRioja",        MAX_NOMBRE);
    strncpy(mapa->regiones[9].nombre,  "Madrid",         MAX_NOMBRE);
    strncpy(mapa->regiones[10].nombre, "Extremadura",    MAX_NOMBRE);
    strncpy(mapa->regiones[11].nombre, "Andalucia",      MAX_NOMBRE);

    agregarVecino(mapa, 0,  1); /* Galicia       - Asturias      */
    agregarVecino(mapa, 0,  7); /* Galicia       - CastillaYLeon */
    agregarVecino(mapa, 1,  2); /* Asturias      - Cantabria     */
    agregarVecino(mapa, 1,  7); /* Asturias      - CastillaYLeon */
    agregarVecino(mapa, 2,  3); /* Cantabria     - PaisVasco     */
    agregarVecino(mapa, 2,  7); /* Cantabria     - CastillaYLeon */
    agregarVecino(mapa, 2,  8); /* Cantabria     - LaRioja       */
    agregarVecino(mapa, 3,  4); /* PaisVasco     - Navarra       */
    agregarVecino(mapa, 3,  8); /* PaisVasco     - LaRioja       */
    agregarVecino(mapa, 4,  5); /* Navarra       - Aragon        */
    agregarVecino(mapa, 4,  8); /* Navarra       - LaRioja       */
    agregarVecino(mapa, 5,  6); /* Aragon        - Cataluna      */
    agregarVecino(mapa, 5,  7); /* Aragon        - CastillaYLeon */
    agregarVecino(mapa, 5,  8); /* Aragon        - LaRioja       */
    agregarVecino(mapa, 7,  8); /* CastillaYLeon - LaRioja       */
    agregarVecino(mapa, 7,  9); /* CastillaYLeon - Madrid        */
    agregarVecino(mapa, 7, 10); /* CastillaYLeon - Extremadura   */
    agregarVecino(mapa, 9, 10); /* Madrid        - Extremadura   */
    agregarVecino(mapa, 10,11); /* Extremadura   - Andalucia     */
}
