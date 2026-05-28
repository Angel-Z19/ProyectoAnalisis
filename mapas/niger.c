#include <string.h>
#include "niger.h"

/*
 * Niger tiene 8 regiones (departamentos):
 * 0-Agadez, 1-Diffa, 2-Dosso, 3-Maradi,
 * 4-Tahoua, 5-Tillaberi, 6-Zinder, 7-Niamey
 */
void cargarNiger(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Niger", MAX_NOMBRE);
    mapa->numRegiones = 8;

    /* Inicializar todas las regiones */
    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color      = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre, "Agadez",    MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre, "Diffa",     MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre, "Dosso",     MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre, "Maradi",    MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre, "Tahoua",    MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre, "Tillaberi", MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre, "Zinder",    MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre, "Niamey",    MAX_NOMBRE);

    /* Vecindades reales de Niger */
    agregarVecino(mapa, 0, 1); /* Agadez   - Diffa     */
    agregarVecino(mapa, 0, 4); /* Agadez   - Tahoua    */
    agregarVecino(mapa, 0, 6); /* Agadez   - Zinder    */
    agregarVecino(mapa, 1, 6); /* Diffa    - Zinder    */
    agregarVecino(mapa, 2, 3); /* Dosso    - Maradi    */
    agregarVecino(mapa, 2, 4); /* Dosso    - Tahoua    */
    agregarVecino(mapa, 2, 5); /* Dosso    - Tillaberi */
    agregarVecino(mapa, 2, 7); /* Dosso    - Niamey    */
    agregarVecino(mapa, 3, 4); /* Maradi   - Tahoua    */
    agregarVecino(mapa, 3, 6); /* Maradi   - Zinder    */
    agregarVecino(mapa, 4, 5); /* Tahoua   - Tillaberi */
    agregarVecino(mapa, 5, 7); /* Tillaberi- Niamey    */
}
