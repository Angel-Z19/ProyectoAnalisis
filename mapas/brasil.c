#include <string.h>
#include "brasil.h"

/*
 * Brasil - 10 estados del noreste/centro para mantenerlo manejable:
 * 0-Maranhao,  1-Piaui,      2-Ceara,    3-RioGrandeDoNorte,
 * 4-Paraiba,   5-Pernambuco, 6-Alagoas,  7-Sergipe,
 * 8-Bahia,     9-Tocantins
 */
void cargarBrasil(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Brasil (Noreste)", MAX_NOMBRE);
    mapa->numRegiones = 10;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color      = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre, "Maranhao",          MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre, "Piaui",             MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre, "Ceara",             MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre, "RioGrandeDoNorte",  MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre, "Paraiba",           MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre, "Pernambuco",        MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre, "Alagoas",           MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre, "Sergipe",           MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre, "Bahia",             MAX_NOMBRE);
    strncpy(mapa->regiones[9].nombre, "Tocantins",         MAX_NOMBRE);

    agregarVecino(mapa, 0, 1); /* Maranhao   - Piaui            */
    agregarVecino(mapa, 0, 9); /* Maranhao   - Tocantins        */
    agregarVecino(mapa, 1, 2); /* Piaui      - Ceara            */
    agregarVecino(mapa, 1, 8); /* Piaui      - Bahia            */
    agregarVecino(mapa, 1, 9); /* Piaui      - Tocantins        */
    agregarVecino(mapa, 2, 3); /* Ceara      - RioGrandeDoNorte */
    agregarVecino(mapa, 2, 4); /* Ceara      - Paraiba          */
    agregarVecino(mapa, 2, 5); /* Ceara      - Pernambuco       */
    agregarVecino(mapa, 3, 4); /* RioGrande  - Paraiba          */
    agregarVecino(mapa, 4, 5); /* Paraiba    - Pernambuco       */
    agregarVecino(mapa, 5, 6); /* Pernambuco - Alagoas          */
    agregarVecino(mapa, 5, 8); /* Pernambuco - Bahia            */
    agregarVecino(mapa, 6, 7); /* Alagoas    - Sergipe          */
    agregarVecino(mapa, 6, 8); /* Alagoas    - Bahia            */
    agregarVecino(mapa, 7, 8); /* Sergipe    - Bahia            */
    agregarVecino(mapa, 8, 9); /* Bahia      - Tocantins        */
}
