#include <string.h>
#include "brasil.h"

/*
 * Brasil completo - 27 unidades federativas:
 * 0-Acre, 1-Alagoas, 2-Amapa, 3-Amazonas, 4-Bahia,
 * 5-Ceara, 6-DistritoFederal, 7-EspiritoSanto, 8-Goias,
 * 9-Maranhao, 10-MatoGrosso, 11-MatoGrossoDoSul,
 * 12-MinasGerais, 13-Para, 14-Paraiba, 15-Parana,
 * 16-Pernambuco, 17-Piaui, 18-RioDeJaneiro,
 * 19-RioGrandeDoNorte, 20-RioGrandeDoSul, 21-Rondonia,
 * 22-Roraima, 23-SantaCatarina, 24-SaoPaulo,
 * 25-Sergipe, 26-Tocantins
 */
void cargarBrasil(Mapa *mapa)
{
    int i;

    strncpy(mapa->nombre, "Brasil", MAX_NOMBRE);
    mapa->numRegiones = 27;

    for (i = 0; i < mapa->numRegiones; i++) {
        mapa->regiones[i].numVecinos = 0;
        mapa->regiones[i].color = SIN_COLOR;
    }

    strncpy(mapa->regiones[0].nombre,  "Acre",              MAX_NOMBRE);
    strncpy(mapa->regiones[1].nombre,  "Alagoas",           MAX_NOMBRE);
    strncpy(mapa->regiones[2].nombre,  "Amapa",             MAX_NOMBRE);
    strncpy(mapa->regiones[3].nombre,  "Amazonas",          MAX_NOMBRE);
    strncpy(mapa->regiones[4].nombre,  "Bahia",             MAX_NOMBRE);
    strncpy(mapa->regiones[5].nombre,  "Ceara",             MAX_NOMBRE);
    strncpy(mapa->regiones[6].nombre,  "DistritoFederal",   MAX_NOMBRE);
    strncpy(mapa->regiones[7].nombre,  "EspiritoSanto",     MAX_NOMBRE);
    strncpy(mapa->regiones[8].nombre,  "Goias",             MAX_NOMBRE);
    strncpy(mapa->regiones[9].nombre,  "Maranhao",          MAX_NOMBRE);
    strncpy(mapa->regiones[10].nombre, "MatoGrosso",        MAX_NOMBRE);
    strncpy(mapa->regiones[11].nombre, "MatoGrossoDoSul",   MAX_NOMBRE);
    strncpy(mapa->regiones[12].nombre, "MinasGerais",       MAX_NOMBRE);
    strncpy(mapa->regiones[13].nombre, "Para",              MAX_NOMBRE);
    strncpy(mapa->regiones[14].nombre, "Paraiba",           MAX_NOMBRE);
    strncpy(mapa->regiones[15].nombre, "Parana",            MAX_NOMBRE);
    strncpy(mapa->regiones[16].nombre, "Pernambuco",        MAX_NOMBRE);
    strncpy(mapa->regiones[17].nombre, "Piaui",             MAX_NOMBRE);
    strncpy(mapa->regiones[18].nombre, "RioDeJaneiro",      MAX_NOMBRE);
    strncpy(mapa->regiones[19].nombre, "RioGrandeDoNorte",  MAX_NOMBRE);
    strncpy(mapa->regiones[20].nombre, "RioGrandeDoSul",    MAX_NOMBRE);
    strncpy(mapa->regiones[21].nombre, "Rondonia",          MAX_NOMBRE);
    strncpy(mapa->regiones[22].nombre, "Roraima",           MAX_NOMBRE);
    strncpy(mapa->regiones[23].nombre, "SantaCatarina",     MAX_NOMBRE);
    strncpy(mapa->regiones[24].nombre, "SaoPaulo",          MAX_NOMBRE);
    strncpy(mapa->regiones[25].nombre, "Sergipe",           MAX_NOMBRE);
    strncpy(mapa->regiones[26].nombre, "Tocantins",         MAX_NOMBRE);

    agregarVecino(mapa, 0, 3);   /* Acre - Amazonas */
    agregarVecino(mapa, 0, 21);  /* Acre - Rondonia */

    agregarVecino(mapa, 1, 4);   /* Alagoas - Bahia */
    agregarVecino(mapa, 1, 16);  /* Alagoas - Pernambuco */
    agregarVecino(mapa, 1, 25);  /* Alagoas - Sergipe */

    agregarVecino(mapa, 2, 13);  /* Amapa - Para */

    agregarVecino(mapa, 3, 13);  /* Amazonas - Para */
    agregarVecino(mapa, 3, 21);  /* Amazonas - Rondonia */
    agregarVecino(mapa, 3, 22);  /* Amazonas - Roraima */
    agregarVecino(mapa, 3, 10);  /* Amazonas - MatoGrosso */

    agregarVecino(mapa, 4, 7);   /* Bahia - EspiritoSanto */
    agregarVecino(mapa, 4, 8);   /* Bahia - Goias */
    agregarVecino(mapa, 4, 12);  /* Bahia - MinasGerais */
    agregarVecino(mapa, 4, 16);  /* Bahia - Pernambuco */
    agregarVecino(mapa, 4, 17);  /* Bahia - Piaui */
    agregarVecino(mapa, 4, 25);  /* Bahia - Sergipe */
    agregarVecino(mapa, 4, 26);  /* Bahia - Tocantins */

    agregarVecino(mapa, 5, 14);  /* Ceara - Paraiba */
    agregarVecino(mapa, 5, 16);  /* Ceara - Pernambuco */
    agregarVecino(mapa, 5, 17);  /* Ceara - Piaui */
    agregarVecino(mapa, 5, 19);  /* Ceara - RioGrandeDoNorte */

    agregarVecino(mapa, 6, 8);   /* DistritoFederal - Goias */
    agregarVecino(mapa, 6, 12);  /* DistritoFederal - MinasGerais */

    agregarVecino(mapa, 7, 12);  /* EspiritoSanto - MinasGerais */
    agregarVecino(mapa, 7, 18);  /* EspiritoSanto - RioDeJaneiro */

    agregarVecino(mapa, 8, 10);  /* Goias - MatoGrosso */
    agregarVecino(mapa, 8, 11);  /* Goias - MatoGrossoDoSul */
    agregarVecino(mapa, 8, 12);  /* Goias - MinasGerais */
    agregarVecino(mapa, 8, 26);  /* Goias - Tocantins */

    agregarVecino(mapa, 9, 13);  /* Maranhao - Para */
    agregarVecino(mapa, 9, 17);  /* Maranhao - Piaui */
    agregarVecino(mapa, 9, 26);  /* Maranhao - Tocantins */

    agregarVecino(mapa, 10, 11); /* MatoGrosso - MatoGrossoDoSul */
    agregarVecino(mapa, 10, 13); /* MatoGrosso - Para */
    agregarVecino(mapa, 10, 21); /* MatoGrosso - Rondonia */
    agregarVecino(mapa, 10, 26); /* MatoGrosso - Tocantins */

    agregarVecino(mapa, 11, 12); /* MatoGrossoDoSul - MinasGerais */
    agregarVecino(mapa, 11, 15); /* MatoGrossoDoSul - Parana */
    agregarVecino(mapa, 11, 24); /* MatoGrossoDoSul - SaoPaulo */

    agregarVecino(mapa, 12, 18); /* MinasGerais - RioDeJaneiro */
    agregarVecino(mapa, 12, 24); /* MinasGerais - SaoPaulo */

    agregarVecino(mapa, 13, 22); /* Para - Roraima */
    agregarVecino(mapa, 13, 26); /* Para - Tocantins */

    agregarVecino(mapa, 14, 16); /* Paraiba - Pernambuco */
    agregarVecino(mapa, 14, 19); /* Paraiba - RioGrandeDoNorte */

    agregarVecino(mapa, 15, 23); /* Parana - SantaCatarina */
    agregarVecino(mapa, 15, 24); /* Parana - SaoPaulo */

    agregarVecino(mapa, 16, 17); /* Pernambuco - Piaui */

    agregarVecino(mapa, 18, 24); /* RioDeJaneiro - SaoPaulo */

    agregarVecino(mapa, 20, 23); /* RioGrandeDoSul - SantaCatarina */
}