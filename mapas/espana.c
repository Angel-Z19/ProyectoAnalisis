#include <string.h>
#include "espana.h"

/*
 * Espana completa - 17 comunidades autonomas:
 * 0-Galicia, 1-Asturias, 2-Cantabria, 3-PaisVasco,
 * 4-Navarra, 5-LaRioja, 6-Aragon, 7-Cataluna,
 * 8-CastillaYLeon, 9-Madrid, 10-CastillaLaMancha,
 * 11-Extremadura, 12-Andalucia, 13-Murcia,
 * 14-ComunidadValenciana, 15-IslasBaleares, 16-Canarias
 */
void cargarEspana(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Espana", MAX_NOMBRE);
    mapa->numRegiones = 17;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre,  "Galicia",              MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre,  "Asturias",             MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre,  "Cantabria",            MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre,  "PaisVasco",            MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre,  "Navarra",              MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre,  "LaRioja",              MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre,  "Aragon",               MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre,  "Cataluna",             MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre,  "CastillaYLeon",        MAX_NOMBRE);
    strncpy(mapa->regiones[9].nombre,  "Madrid",               MAX_NOMBRE);
    strncpy(mapa->regiones[10].nombre, "CastillaLaMancha",     MAX_NOMBRE);
    strncpy(mapa->regiones[11].nombre, "Extremadura",          MAX_NOMBRE);
    strncpy(mapa->regiones[12].nombre, "Andalucia",            MAX_NOMBRE);
    strncpy(mapa->regiones[13].nombre, "Murcia",               MAX_NOMBRE);
    strncpy(mapa->regiones[14].nombre, "ComunidadValenciana",  MAX_NOMBRE);
    strncpy(mapa->regiones[15].nombre, "IslasBaleares",        MAX_NOMBRE);
    strncpy(mapa->regiones[16].nombre, "Canarias",             MAX_NOMBRE);

    agregarVecino(mapa, 0, 1);    /* Galicia - Asturias */
    agregarVecino(mapa, 0, 8);    /* Galicia - CastillaYLeon */

    agregarVecino(mapa, 1, 2);    /* Asturias - Cantabria */
    agregarVecino(mapa, 1, 8);    /* Asturias - CastillaYLeon */

    agregarVecino(mapa, 2, 3);    /* Cantabria - PaisVasco */
    agregarVecino(mapa, 2, 8);    /* Cantabria - CastillaYLeon */

    agregarVecino(mapa, 3, 4);    /* PaisVasco - Navarra */
    agregarVecino(mapa, 3, 5);    /* PaisVasco - LaRioja */
    agregarVecino(mapa, 3, 8);    /* PaisVasco - CastillaYLeon */

    agregarVecino(mapa, 4, 5);    /* Navarra - LaRioja */
    agregarVecino(mapa, 4, 6);    /* Navarra - Aragon */

    agregarVecino(mapa, 5, 6);    /* LaRioja - Aragon */
    agregarVecino(mapa, 5, 8);    /* LaRioja - CastillaYLeon */

    agregarVecino(mapa, 6, 7);    /* Aragon - Cataluna */
    agregarVecino(mapa, 6, 8);    /* Aragon - CastillaYLeon */
    agregarVecino(mapa, 6, 10);   /* Aragon - CastillaLaMancha */
    agregarVecino(mapa, 6, 14);   /* Aragon - ComunidadValenciana */

    agregarVecino(mapa, 7, 14);   /* Cataluna - ComunidadValenciana */

    agregarVecino(mapa, 8, 9);    /* CastillaYLeon - Madrid */
    agregarVecino(mapa, 8, 10);   /* CastillaYLeon - CastillaLaMancha */
    agregarVecino(mapa, 8, 11);   /* CastillaYLeon - Extremadura */

    agregarVecino(mapa, 9, 10);   /* Madrid - CastillaLaMancha */

    agregarVecino(mapa, 10, 11);  /* CastillaLaMancha - Extremadura */
    agregarVecino(mapa, 10, 12);  /* CastillaLaMancha - Andalucia */
    agregarVecino(mapa, 10, 13);  /* CastillaLaMancha - Murcia */
    agregarVecino(mapa, 10, 14);  /* CastillaLaMancha - ComunidadValenciana */

    agregarVecino(mapa, 11, 12);  /* Extremadura - Andalucia */

    agregarVecino(mapa, 12, 13);  /* Andalucia - Murcia */

    agregarVecino(mapa, 13, 14);  /* Murcia - ComunidadValenciana */

    /*
     * IslasBaleares y Canarias no tienen vecindades terrestres
     * con otras comunidades autonomas españolas.
     */
}