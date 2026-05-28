#include <stdio.h>
#include <string.h>
#include "mapa.h"
#include "backtracking.h"
#include "graphviz.h"
#include "mapas/niger.h"
#include "mapas/chad.h"
#include "mapas/brasil.h"
#include "mapas/espana.h"

static void mostrarMenu(void)
{
    printf("╔══════════════════════════════════╗\n");
    printf("║   Coloreo de Mapas con           ║\n");
    printf("║   Backtracking                   ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Niger                        ║\n");
    printf("║  2. Chad                         ║\n");
    printf("║  3. Brasil (Noreste)             ║\n");
    printf("║  4. Espana                       ║\n");
    printf("║  5. Correr todos los mapas       ║\n");
    printf("║  0. Salir                        ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("Selecciona una opcion: ");
}

static void procesarMapa(Mapa *mapa)
{
    char rutaDot[128];
    char rutaPng[128];

    printf("\nProcesando: %s...\n", mapa->nombre);

    int minColores = encontrarMinimoColores(mapa);

    if (minColores == -1) {
        printf("Error: no se pudo colorear %s\n", mapa->nombre);
        return;
    }

    imprimirResultado(mapa, minColores);

    /* Generar visualizacion */
    snprintf(rutaDot, sizeof(rutaDot), "salidas/%s.dot", mapa->nombre);
    snprintf(rutaPng, sizeof(rutaPng), "salidas/%s.png", mapa->nombre);

    generarDot(mapa, rutaDot);
    generarPng(rutaDot, rutaPng);
}

int main(void)
{
    Mapa mapa;
    int opcion;

    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) break;

        switch (opcion) {
            case 1:
                cargarNiger(&mapa);
                procesarMapa(&mapa);
                break;
            case 2:
                cargarChad(&mapa);
                procesarMapa(&mapa);
                break;
            case 3:
                cargarBrasil(&mapa);
                procesarMapa(&mapa);
                break;
            case 4:
                cargarEspana(&mapa);
                procesarMapa(&mapa);
                break;
            case 5: {
                Mapa mapas[4];
                cargarNiger(&mapas[0]);
                cargarChad(&mapas[1]);
                cargarBrasil(&mapas[2]);
                cargarEspana(&mapas[3]);
                int i;
                for (i = 0; i < 4; i++) {
                    procesarMapa(&mapas[i]);
                }
                break;
            }
            case 0:
                printf("Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}
