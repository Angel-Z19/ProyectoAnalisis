#include <stdio.h>
#include <stdlib.h>
#include "graphviz.h"

/* Mapeo de indices de color a nombres reconocidos por Graphviz */
static const char *COLORES_GV[MAX_COLORES] = {
    "tomato",       /* 0 - rojo    */
    "steelblue",    /* 1 - azul    */
    "mediumseagreen", /* 2 - verde */
    "gold",         /* 3 - amarillo */
    "darkorange",   /* 4 - naranja */
    "mediumpurple", /* 5 - violeta */
    "peru",         /* 6 - cafe    */
    "hotpink"       /* 7 - rosa    */
};

const char *colorAGraphviz(int color)
{
    if (color >= 0 && color < MAX_COLORES) {
        return COLORES_GV[color];
    }
    return "white";
}

void generarDot(const Mapa *mapa, const char *rutaArchivo)
{
    FILE *f = fopen(rutaArchivo, "w");
    if (!f) {
        fprintf(stderr, "Error: no se pudo crear %s\n", rutaArchivo);
        return;
    }

    int i, j;

    fprintf(f, "graph \"%s\" {\n", mapa->nombre);
    fprintf(f, "    layout=dot\n");
    fprintf(f, "    overlap=false\n");
    fprintf(f, "    node [style=filled, fontname=\"Helvetica\", fontsize=10]\n");
    fprintf(f, "    edge [color=gray50]\n\n");

    /* Nodos con su color */
    for (i = 0; i < mapa->numRegiones; i++) {
        fprintf(f, "    \"%s\" [fillcolor=%s]\n",
                mapa->regiones[i].nombre,
                colorAGraphviz(mapa->regiones[i].color));
    }

    fprintf(f, "\n");

    /* Aristas (solo una direccion para evitar duplicados) */
    for (i = 0; i < mapa->numRegiones; i++) {
        for (j = 0; j < mapa->regiones[i].numVecinos; j++) {
            int vecIdx = mapa->regiones[i].vecinos[j];
            if (vecIdx > i) { /* solo si vecino tiene indice mayor */
                fprintf(f, "    \"%s\" -- \"%s\"\n",
                        mapa->regiones[i].nombre,
                        mapa->regiones[vecIdx].nombre);
            }
        }
    }

    fprintf(f, "}\n");
    fclose(f);
    printf("Archivo .dot generado: %s\n", rutaArchivo);
}

void generarPng(const char *rutaDot, const char *rutaPng)
{
    char comando[256];
    snprintf(comando, sizeof(comando),
             "dot -Tpng \"%s\" -o \"%s\"", rutaDot, rutaPng);

    if (system(comando) == 0) {
        printf("Imagen generada: %s\n", rutaPng);
    } else {
        fprintf(stderr, "Error al ejecutar Graphviz. Verifica que 'dot' este instalado.\n");
    }
}
