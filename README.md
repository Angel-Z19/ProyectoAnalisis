# Coloreo de Mapas con Backtracking

Proyecto para la clase de Análisis de Algoritmos.  
Determina el número mínimo de colores necesarios para colorear un mapa sin que regiones vecinas compartan color.

## Integrantes
- (nombre 1)
- (nombre 2)

## Estructura del proyecto

```
ColorearMapa/
├── main.c              # Menú principal y flujo del programa
├── region.h            # Estructura Region (nombre, vecinos, color)
├── mapa.h / mapa.c     # Estructura Mapa y funciones generales
├── backtracking.h/.c   # Algoritmo de backtracking
├── graphviz.h/.c       # Generación de archivos .dot y .png
├── mapas/
│   ├── niger.c         # Departamentos de Níger
│   ├── chad.c          # Regiones de Chad
│   ├── brasil.c        # Estados del noreste de Brasil
│   └── espana.c        # Comunidades autónomas de España
└── salidas/            # Imágenes y archivos .dot generados
```

## Dependencias

- `gcc` (compilador C)
- `graphviz` (para generar imágenes PNG)

### Instalar Graphviz

```bash
# Ubuntu/Debian
sudo apt install graphviz

# macOS
brew install graphviz
```

## Compilar y ejecutar

```bash
make
./colorear_mapa
```

## Limpiar compilados

```bash
make clean
```

## Algoritmo

El backtracking funciona así:

1. Se intenta colorear con `n = 1` color, luego `n = 2`, etc.
2. Para cada `n`, se asigna un color a cada región de forma recursiva.
3. Si en algún punto ningún color es válido para una región, se regresa (`backtrack`) y se prueba otro color en la región anterior.
4. El primer `n` con el que se encuentra solución es el mínimo.

La complejidad en el peor caso es **O(k^n)** donde `k` es el número de colores y `n` el número de regiones, aunque el backtracking poda ramas inválidas rápidamente en la práctica.

## Paleta de colores

| Índice | Nombre   | Color Graphviz   |
|--------|----------|------------------|
| 0      | Rojo     | tomato           |
| 1      | Azul     | steelblue        |
| 2      | Verde    | mediumseagreen   |
| 3      | Amarillo | gold             |
| 4      | Naranja  | darkorange       |
| 5      | Violeta  | mediumpurple     |
| 6      | Café     | peru             |
| 7      | Rosa     | hotpink          |
