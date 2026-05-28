#include <string.h>
#include "chad.h"

/*
 * Chad - 9 regiones representativas:
 * 0-Borkou, 1-Ennedi, 2-Tibesti, 3-Kanem,
 * 4-Lac,    5-BET,    6-Ouaddai, 7-Guera, 8-N'Djamena
 */
void cargarChad(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Chad", MAX_NOMBRE);
    mapa->numRegiones = 9;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color      = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre, "Borkou",    MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre, "Ennedi",    MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre, "Tibesti",   MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre, "Kanem",     MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre, "Lac",       MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre, "BET",       MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre, "Ouaddai",   MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre, "Guera",     MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre, "N'Djamena", MAX_NOMBRE);

    agregarVecino(mapa, 0, 1); /* Borkou  - Ennedi   */
    agregarVecino(mapa, 0, 2); /* Borkou  - Tibesti  */
    agregarVecino(mapa, 0, 5); /* Borkou  - BET      */
    agregarVecino(mapa, 0, 6); /* Borkou  - Ouaddai  */
    agregarVecino(mapa, 1, 6); /* Ennedi  - Ouaddai  */
    agregarVecino(mapa, 2, 3); /* Tibesti - Kanem    */
    agregarVecino(mapa, 3, 4); /* Kanem   - Lac      */
    agregarVecino(mapa, 3, 8); /* Kanem   - N'Djamena*/
    agregarVecino(mapa, 4, 8); /* Lac     - N'Djamena*/
    agregarVecino(mapa, 5, 6); /* BET     - Ouaddai  */
    agregarVecino(mapa, 6, 7); /* Ouaddai - Guera    */
    agregarVecino(mapa, 7, 8); /* Guera   - N'Djamena*/
}
