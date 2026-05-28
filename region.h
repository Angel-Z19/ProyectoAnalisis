#ifndef REGION_H
#define REGION_H

#define MAX_VECINOS  20
#define MAX_NOMBRE   50
#define MAX_COLORES   8
#define SIN_COLOR    -1

typedef struct {
    char nombre[MAX_NOMBRE];
    int  vecinos[MAX_VECINOS]; /* indices dentro del arreglo de regiones */
    int  numVecinos;
    int  color;                /* SIN_COLOR = sin asignar, 0..7 = color */
} Region;

#endif /* REGION_H */
