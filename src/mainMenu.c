#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>

#include "auxiliar.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "mergeSort.h"

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

char menuCarga(void);
int * creacionMatriz(int *length);
void asciiArt(void);
char menuOrdenacion(void);
void funcionSalidaPrograma(int * matriz);
void mostrarResultados(int * matriz, int longitud);
void mayorMenor(int * matriz, int longitud);

int main(int argc, char const *argv[]){
    
    char seleccionMenu;
    char seleccionOrdenacion;
    int * matriz;
    int longitud;
    
    if(argc > 1){
        printf("Por favor, ejecuta el programa sin ningun argumento");
    }

    do {

        do {
            seleccionMenu = menuCarga();
        
            switch (seleccionMenu){
            case '1':
                matriz = creacionMatriz(&longitud);
                break;
            case '2':
                break;
            case 'S':
                funcionSalidaPrograma(matriz);
            case 's':
                funcionSalidaPrograma(matriz);
            default:
                break;
            }

        } while(seleccionMenu != '1' && seleccionMenu != '2' && seleccionMenu != 'S' && seleccionMenu != 's');
        

        do{
            seleccionOrdenacion = menuOrdenacion();
            
            switch (seleccionOrdenacion){
            case '1':
                bubbleSort(matriz, longitud);
                mostrarResultados(matriz, longitud);
                break;
            case '2':
                insertionSort(matriz, longitud);
                mostrarResultados(matriz, longitud);
                break;
            case '3':
                selectionSort(matriz, longitud);
                mostrarResultados(matriz, longitud);
                break;
            case '4':
                quickSort(matriz, longitud);
                mostrarResultados(matriz, longitud);
                break;
            case '5':
                mergeSort(matriz, longitud);
                mostrarResultados(matriz, longitud);
                break;
            default:
                break;
            }


        } while (seleccionOrdenacion != '1' && seleccionOrdenacion != '2' && seleccionOrdenacion != '3' && seleccionOrdenacion != '4' && seleccionOrdenacion != '5');
        




    } while(seleccionMenu != 'S' && seleccionMenu != 's');
    

    return 0;
}

void mostrarResultados(int * matriz, int longitud){

    char seleccionMayorMenor,seleccionSalida, seleccionArchivo;
    bool guardarArchivo = false;
    char nombreArchivo[50];
    char nombreArchivoExtension[54];

    do{  
        asciiArt();
        puts("\nFORMATO DEL RESULTADO: \n");
        puts("  1 - De mayor a menor");
        puts("  2 - De menor a mayor");
        printf("\nSELECCION: ");
        scanf("%c", &seleccionMayorMenor);
        system(CLEAR_SCREEN);
    } while (seleccionMayorMenor != '1' && seleccionMayorMenor != '2');
    
    
    do {
        asciiArt();

        printf("\nLa matriz ha sido ordenada correctamente:\n");

        if(seleccionMayorMenor == '1') mayorMenor(matriz, longitud);

        printf("[ ");
        for(int i = 0; i < longitud - 1; i++){
            printf("%d, ", matriz[i]);
        }
        printf("%d]\n\n", matriz[longitud - 2]);
        puts("============================================================================================");
        printf("\nAlmacenar los resultados en un archivo? (S/N): ");
        scanf(" %c", &seleccionArchivo);
    } while(seleccionArchivo != 'S' && seleccionArchivo != 's' && seleccionArchivo != 'n' && seleccionArchivo != 'N');

    switch(seleccionArchivo){
        case 'S':
            guardarArchivo = true;
            break;
        case 's':
            guardarArchivo = true;
            break;
    }

    if(guardarArchivo){
        printf("Introduce el nombre del archivo txt en el que almacenar los resultados: ");
        scanf(" %s", nombreArchivo);
        if(strstr(nombreArchivo, ".txt") == NULL){
            sprintf(nombreArchivoExtension, "./output/%s.txt", nombreArchivo);
        }else{
            sprintf(nombreArchivoExtension, "./output/%s", nombreArchivo);
        }

        FILE * resultado = fopen(nombreArchivoExtension, "w");
        if(resultado == NULL){
            printf("Error al abrir el archivo, saliendo...");
            funcionSalidaPrograma(matriz);
        }

        for(int i = 0; i < longitud; i++){
            fprintf(resultado, "%d ", matriz[i]);
        }

        printf("\nGuardado correctamente en '%s'\n", nombreArchivo);
    }

    do {
        printf("\n\n\nSalir del programa? (S/N): ");
        scanf(" %c", &seleccionSalida);

        switch (seleccionSalida)
        {
        case 's':
            funcionSalidaPrograma(matriz);
            break;
        case 'S':
            funcionSalidaPrograma(matriz);
            break;
        case 'n':
            free(matriz);
            break;
        case 'N': 
            free(matriz);
            break;
        default:
            break;
        }
    } while(seleccionSalida!= 's' && seleccionSalida != 'n' && seleccionSalida != 'S' && seleccionSalida != 'N');

}
char menuCarga(void){

    char seleccion;
    asciiArt();
    printf("\n-> Ordenacion de una matriz de numeros enteros mediante 5 algoritmos distintos\n");
    printf("\nOPCIONES: \n\n");
    puts("  1 - Introducir matriz por teclado");
    puts("  2 - Cargar matriz desde un archivo");
    puts("  S - Salir");
    printf("\nSELECCION: ");
    scanf("%c", &seleccion);
    system(CLEAR_SCREEN);
    return seleccion;
}

char menuOrdenacion(void){

    char seleccion;

    asciiArt();

    printf("\nALGORITMOS DISPONIBLES: \n\n");
    puts("  1 - Bubble Sort");
    puts("  2 - Insertion Sort");
    puts("  3 - Selection Sort");
    puts("  4 - Quick Sort");
    puts("  5 - Merge Sort");
    printf("\nSELECCION: ");
    scanf(" %c", &seleccion);
    getchar();
    system(CLEAR_SCREEN);
    return seleccion;
}

int * creacionMatriz(int *length){
    int longitud; 
    asciiArt();
    do {
        printf("\nLongitud de la matriz: ");
        scanf("%d", &longitud);        
    } while(longitud <= 0);

    *length = longitud;
    int * array = malloc(longitud * sizeof(int));

    if(array == NULL){
        printf("Error en la reserva de memoria, saliendo...");
        exit(-1);
    }

    printf("\nIntroduce la matriz: \n");

    for(int i = 0; i < longitud; i++){
        printf("[%d] => ", i);
        scanf("%d", &array[i]);
    }
    
    printf("\nLa matriz ha sido cargada correctamente, pulsa enter para continuar");
    getchar();
    getchar();

    return array;
}

void asciiArt(void){
    system(CLEAR_SCREEN);
    puts("============================================================================================");
    puts(" .d8888b.                   888    d8b                                 888                   ");
    puts("d88P  Y88b                  888    Y8P                                 888                   ");
    puts("Y88b.                       888                                        888                   ");
    puts(" \"Y888b.    .d88b.  888d888 888888 888 88888b.   .d88b.        8888b.  888  .d88b.   .d88b.  ");
    puts("    \"Y88b. d88\"\"88b 888P\"   888    888 888 \"88b d88P\"88b          \"88b 888 d88P\"88b d88\"\"88b");
    puts("      \"888 888  888 888     888    888 888  888 888  888      .d888888 888 888  888 888  888 ");
    puts("Y88b  d88P Y88..88P 888     Y88b.  888 888  888 Y88b 888      888  888 888 Y88b 888 Y88..88P ");
    puts(" \"Y8888P\"   \"Y88P\"  888      \"Y888 888 888  888  \"Y88888      \"Y888888 888  \"Y88888  \"Y88P\"  ");
    puts("                                                     888                        888          ");
    puts("                                                Y8b d88P                   Y8b d88P          ");
    puts("                                                 \"Y88P\"                     \"Y88P\"");
    puts("============================================================================================");
}

void funcionSalidaPrograma(int * matriz){
    free(matriz);
    exit(0);
}

void mayorMenor(int * matriz, int longitud){
    int inicio = 0;
    int fin = longitud - 1;

    while (inicio < fin){

        int temp = matriz[inicio];
        matriz[inicio] = matriz[fin];
        matriz[fin] = temp;

        inicio++;
        fin--;
    }
    
}