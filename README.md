![image](https://github.com/0xHugo/Algoritmos-Sorting/assets/120257009/74519486-b568-45f9-9da0-1e5245142ea5)

# Algoritmos Sorting en C
Implementación los siguientes algoritmos en C: 
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort


## Instalacion

Necesario: git gcc  make

Clona el repositorio: 
```bash
  git clone https://github.com/0xHugo/Algoritmos-Sorting
  cd Algoritmos-Sorting
```
Compila mediante el makefile
```bash
  make
```
Ejecuta el .exe creado desde la terminal: 
```bash
  ./algoSorting.exe
```

## Guardar resultados

Si eliges guardar los resultados en un archivo la ruta en la que se guardan es /output

Puedes ver su contenido por la terminal mediante: 
```bash
  cd ./output
  cat <nombreArchivo.txt>
```
O abrirlo con tu editor de texto favorito / notepad

## Roadmap
- [x]  Terminar merge sort
- [x]  Creación de un menú desde el que introducir el array que se vaya a ordenar así como la selección del algoritmo
- [x]  Reserva de ese array mediante memoria dinámica
- [ ]  Lectura de un array desde un archivo
- [x]  Escritura de los resultados a un archivo
- [x]  Posibilidad de elegir el modo de ordenación (de mayor a menor / de menor a mayor)
- [ ]  Modo Benchmark - Ejecución de los 5 algoritmos sobre un mismo array. Devuelve métricas sobre el rendimiento.
- [x]  Makefile para facilitar la compilacion del proyecto
