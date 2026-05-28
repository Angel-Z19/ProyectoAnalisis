#include <string.h>
#include "chad.h"

/*
 * Chad completo - 23 provincias:
 * 0-BahrElGazel, 1-Batha, 2-Borkou, 3-ChariBaguirmi,
 * 4-EnnediEst, 5-EnnediOuest, 6-Guera, 7-HadjerLamis,
 * 8-Kanem, 9-Lac, 10-LogoneOccidental, 11-LogoneOriental,
 * 12-Mandoul, 13-MayoKebbiEst, 14-MayoKebbiOuest,
 * 15-MoyenChari, 16-Ouaddai, 17-Salamat, 18-Sila,
 * 19-Tandjile, 20-Tibesti, 21-WadiFira, 22-NDjamena
 */
void cargarChad(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Chad", MAX_NOMBRE);
    mapa->numRegiones = 23;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre,  "BahrElGazel",      MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre,  "Batha",            MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre,  "Borkou",           MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre,  "ChariBaguirmi",    MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre,  "EnnediEst",        MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre,  "EnnediOuest",      MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre,  "Guera",            MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre,  "HadjerLamis",      MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre,  "Kanem",            MAX_NOMBRE);
    strncpy(mapa->regiones[9].nombre,  "Lac",              MAX_NOMBRE);
    strncpy(mapa->regiones[10].nombre, "LogoneOccidental", MAX_NOMBRE);
    strncpy(mapa->regiones[11].nombre, "LogoneOriental",   MAX_NOMBRE);
    strncpy(mapa->regiones[12].nombre, "Mandoul",          MAX_NOMBRE);
    strncpy(mapa->regiones[13].nombre, "MayoKebbiEst",     MAX_NOMBRE);
    strncpy(mapa->regiones[14].nombre, "MayoKebbiOuest",   MAX_NOMBRE);
    strncpy(mapa->regiones[15].nombre, "MoyenChari",       MAX_NOMBRE);
    strncpy(mapa->regiones[16].nombre, "Ouaddai",          MAX_NOMBRE);
    strncpy(mapa->regiones[17].nombre, "Salamat",          MAX_NOMBRE);
    strncpy(mapa->regiones[18].nombre, "Sila",             MAX_NOMBRE);
    strncpy(mapa->regiones[19].nombre, "Tandjile",         MAX_NOMBRE);
    strncpy(mapa->regiones[20].nombre, "Tibesti",          MAX_NOMBRE);
    strncpy(mapa->regiones[21].nombre, "WadiFira",         MAX_NOMBRE);
    strncpy(mapa->regiones[22].nombre, "NDjamena",         MAX_NOMBRE);

    agregarVecino(mapa, 20, 2);  /* Tibesti - Borkou */

    agregarVecino(mapa, 2, 5);   /* Borkou - EnnediOuest */
    agregarVecino(mapa, 2, 8);   /* Borkou - Kanem */
    agregarVecino(mapa, 2, 0);   /* Borkou - BahrElGazel */
    agregarVecino(mapa, 2, 1);   /* Borkou - Batha */

    agregarVecino(mapa, 5, 4);   /* EnnediOuest - EnnediEst */
    agregarVecino(mapa, 5, 21);  /* EnnediOuest - WadiFira */
    agregarVecino(mapa, 4, 21);  /* EnnediEst - WadiFira */

    agregarVecino(mapa, 21, 16); /* WadiFira - Ouaddai */
    agregarVecino(mapa, 21, 1);  /* WadiFira - Batha */

    agregarVecino(mapa, 16, 18); /* Ouaddai - Sila */
    agregarVecino(mapa, 16, 6);  /* Ouaddai - Guera */
    agregarVecino(mapa, 16, 1);  /* Ouaddai - Batha */

    agregarVecino(mapa, 18, 17); /* Sila - Salamat */
    agregarVecino(mapa, 18, 6);  /* Sila - Guera */

    agregarVecino(mapa, 17, 15); /* Salamat - MoyenChari */
    agregarVecino(mapa, 17, 6);  /* Salamat - Guera */
    agregarVecino(mapa, 17, 1);  /* Salamat - Batha */

    agregarVecino(mapa, 1, 0);   /* Batha - BahrElGazel */
    agregarVecino(mapa, 1, 7);   /* Batha - HadjerLamis */
    agregarVecino(mapa, 1, 6);   /* Batha - Guera */

    agregarVecino(mapa, 0, 8);   /* BahrElGazel - Kanem */
    agregarVecino(mapa, 0, 7);   /* BahrElGazel - HadjerLamis */

    agregarVecino(mapa, 8, 9);   /* Kanem - Lac */
    agregarVecino(mapa, 8, 7);   /* Kanem - HadjerLamis */

    agregarVecino(mapa, 9, 7);   /* Lac - HadjerLamis */

    agregarVecino(mapa, 7, 22);  /* HadjerLamis - NDjamena */
    agregarVecino(mapa, 7, 3);   /* HadjerLamis - ChariBaguirmi */
    agregarVecino(mapa, 7, 6);   /* HadjerLamis - Guera */

    agregarVecino(mapa, 22, 3);  /* NDjamena - ChariBaguirmi */

    agregarVecino(mapa, 3, 13);  /* ChariBaguirmi - MayoKebbiEst */
    agregarVecino(mapa, 3, 19);  /* ChariBaguirmi - Tandjile */
    agregarVecino(mapa, 3, 6);   /* ChariBaguirmi - Guera */

    agregarVecino(mapa, 6, 19);  /* Guera - Tandjile */
    agregarVecino(mapa, 6, 12);  /* Guera - Mandoul */
    agregarVecino(mapa, 6, 15);  /* Guera - MoyenChari */

    agregarVecino(mapa, 15, 12); /* MoyenChari - Mandoul */

    agregarVecino(mapa, 12, 11); /* Mandoul - LogoneOriental */
    agregarVecino(mapa, 12, 10); /* Mandoul - LogoneOccidental */
    agregarVecino(mapa, 12, 19); /* Mandoul - Tandjile */

    agregarVecino(mapa, 11, 10); /* LogoneOriental - LogoneOccidental */

    agregarVecino(mapa, 10, 19); /* LogoneOccidental - Tandjile */
    agregarVecino(mapa, 10, 14); /* LogoneOccidental - MayoKebbiOuest */

    agregarVecino(mapa, 14, 13); /* MayoKebbiOuest - MayoKebbiEst */
    agregarVecino(mapa, 14, 19); /* MayoKebbiOuest - Tandjile */

    agregarVecino(mapa, 13, 19); /* MayoKebbiEst - Tandjile */
}