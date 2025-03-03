Medición de Acceso a Arreglos y Búsqueda Binaria en C

Este repositorio contiene dos programas en C:
 - Medición de acceso a memoria en arreglos de diferentes dimensiones (1D, 2D y 3D).
 - Búsqueda binaria en una matriz ordenada de tamaño 1000 x 1000.
Ambos programas están optimizados para medir el rendimiento de acceso a memoria y búsqueda eficiente en estructuras de datos grandes.
---------------------------------------------------------------------------------------------------------------------------------------
* Contenido
- medicion_arreglos.c - Mide el tiempo de acceso a arreglos 1D, 2D y 3D.
- busquedabinaria.c - Implementa una búsqueda binaria en una matriz ordenada de 1000 x 1000 elementos.
---------------------------------------------------------------------------------------------------------------------------------------
Medición de Acceso a Arreglos (medicion_arreglos.c)
Este programa mide el tiempo de acceso a memoria en arreglos de diferentes dimensiones sin modificar sus valores.

* Características
Permite elegir entre:

- Arreglo 1D: 1000 elementos.
- Arreglo 2D: 1000 × 1000 elementos.
- Arreglo 3D: 1000 × 1000 × 1000 elementos.
Usa malloc() para asignar memoria dinámica y free() para liberarla.
Inicializa los arreglos con valores aleatorios antes de iniciar la medición.
Mide solo el tiempo de acceso a memoria, no el de inicialización.

* Diferencias esperadas:
- 1D es el más rápido porque los datos están en memoria contigua.
- 2D es más lento por saltos de fila en memoria.
- 3D es el más lento por acceso disperso en memoria.
---------------------------------------------------------------------------------------------------------------------------------------
Búsqueda Binaria en una Matriz (busquedabinaria.c)
Este programa implementa búsqueda binaria en una matriz ordenada de 1000 × 1000 para encontrar un número dado por el usuario.

* Características
- Genera una matriz con números ordenados aleatoriamente en cada fila.
- Implementa búsqueda binaria en cada fila para localizar un número.
- Mide el tiempo de ejecución de la búsqueda.
- Usa memoria dinámica para almacenar la matriz y la libera correctamente.
Se inicializa la matriz con números ordenados crecientes en cada fila.
Se solicita al usuario un número a buscar.
Se aplica búsqueda binaria en cada fila.
Se mide el tiempo de ejecución desde el inicio hasta la finalización de la búsqueda.
