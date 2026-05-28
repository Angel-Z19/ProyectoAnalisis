#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H

#include "mapa.h"

/*
 * Genera el archivo .dot en la ruta indicada.
 * El mapa debe estar ya coloreado antes de llamar esta funcion.
 */
void generarDot(const Mapa *mapa, const char *rutaArchivo);

/*
 * Llama a Graphviz para convertir el .dot en una imagen .png.
 * Requiere que 'dot' este instalado en el sistema.
 */
void generarPng(const char *rutaDot, const char *rutaPng);

/*
 * Convierte un indice de color (0-7) al nombre de color
 * reconocido por Graphviz.
 */
const char *colorAGraphviz(int color);

#endif /* GRAPHVIZ_H */
