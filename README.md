*ALGORITMOS DE ORDENAMIENTO*

**DESCRIPCIÓN**
En este proyecto se creo con la finalidad de averiguar la efectividad de cada algoritmo de ordenación que vimos en clase de "Matematicas Discretas"
se utilizaron arreglos de tamaños de 10 hasta el 1000 en 10 en 10, para ver como con el paso del tiempo el programa va corriendo mejor. 


**REQUISITOS PARA EJECUTAR EL CODIGO**
Compilador C++ (GCC, Clang o MSVC) con soporte para C++11.
Sistema operativo: Windows, Linux o macOS.
Memoria RAM: Suficiente para manejar arreglos grandes (2GB+ recomendados).

Pasos clave:
Compilar:
g++ -std=c++11 -O2 tu_codigo.cpp -o ejecutable
Ejecutar:
./ejecutable

**Importante**
El programa genera 7 archivos CSV con los resultados.

Usa NUM_PRUEBAS = 10 y MAX_TAMANO = 100 para pruebas rápidas.



**INSTRUCCIONES**
Descarga o copia el código en un archivo llamado algoritmos.cpp.
Abre una terminal (Linux/macOS) o CMD/PowerShell (Windows).
Compila:
g++ -std=c++11 algoritmos.cpp -o algoritmos // Copiar esto
Ejecuta:
./algoritmos        # Linux/macOS
algoritmos.exe      # Windows

Se generarán 7 archivos CSV con los resultados.


**ALGORITMOS**
_ALGORITMO_INSERCIÓN_
Su funcionamiento consiste en recorrer la lista iterando sobre cada elemento, seleccionando en cada paso un valor como clave. 
Luego, este valor se compara con los elementos anteriores de la lista y se desplaza hasta encontrar su posición correcta,
donde se inserta. Este proceso se repite hasta que todos los elementos estén ordenados.

Uso ideal: Datos pequeños o cuando nuevos elementos se añaden dinámicamente.


_ALGORITMO_BURBUJA_
Su funcionamiento consiste en recorrer repetidamente la lista de elementos que se desea ordenar, comparando cada elemento con 
el siguiente y, si están en el orden incorrecto, intercambiándolos de posición. Este proceso se repite varias veces a lo largo 
de la lista hasta que no se requieran más intercambios, lo que indica que los elementos están completamente ordenados.

Uso ideal: Datos pequeños pero es muy infeciente.

_ALGORITMO_SHELL_
Funciona dividiendo la lista en sublistas más pequeñas utilizando un valor de separación llamado gap, que va disminuyendo 
en cada iteración hasta llegar a 1. En cada sublista, se aplica el método de inserción, lo que permite que los elementos se
desplacen más rápidamente hacia su posición correcta.

_ALGORITMO_SELECCIÓN_
Se basa en dividir la lista en dos partes: la sección ordenada y la no ordenada. En cada iteración, busca el elemento 
más pequeño dentro de la parte no ordenada y lo intercambia con el primer elemento de esa sección, expandiendo así la 
parte ordenada. Este proceso se repite hasta que toda la lista queda organizada.


_ALGORITMO_MERGE SORT_
Consiste en dividir repetidamente la lista en mitades hasta que cada sublista contenga un solo elemento. Luego, se combinan estas sublistas de manera ordenada, fusionándolas de forma progresiva hasta reconstruir la lista completa en orden. 

_ALGORITMO_QUICKSORT_
Consiste en seleccionar un elemento como pivote y dividir la lista en dos subconjuntos: uno con los elementos menores o iguales al pivote y otro con los mayores. Luego, se aplica el mismo proceso de manera recursiva en ambas partes hasta que la lista esté completamente ordenada.

_ALGORITMO_HEAP SORT_
Su funcionamiento comienza transformando la lista en un montículo binario máximo, donde el elemento más grande se encuentra en la raíz. Luego, se intercambia la raíz con el último elemento y se reduce el tamaño del montículo, reestructurándolo para mantener la propiedad de orden. Este proceso se repite hasta que todos los elementos estén ordenados.


**GRAFICAS**
![Grafica](https://github.com/user-attachments/assets/6166c789-e026-4a77-9a6c-847aa8a21f2c)


**ANÁLISIS**
Un algoritmo de ordenamiento es un conjunto de instrucciones diseñadas para organizar una lista de elementos en un orden específico. Existen múltiples algoritmos para esta tarea, cada uno con diferentes niveles de eficiencia y adecuación según el tamaño y la estructura de los datos.

Por ejemplo, el algoritmo de Inserción es eficiente en arreglos pequeños debido a su simplicidad y bajo costo computacional. Sin embargo, a medida que la lista crece, su rendimiento se ve gravemente afectado debido a su complejidad cuadrática. En contraste, el algoritmo Merge Sort utiliza una estrategia de divide y vencerás, lo que lo hace más eficiente en listas grandes, aunque su alto consumo de memoria puede ser una desventaja en ciertos casos.

Según la gráfica presentada, se puede analizar el comportamiento de cada algoritmo en función del tamaño de los datos.
Cabe destacar que la gráfica muestra tamaños de hasta 3000 elementos, en contraste con el código original que se ejecutó hasta 1000 elementos. Este ajuste se realizó con la finalidad de reducir la cantidad de fluctuaciones y facilitar la comparación.

Al observar los resultados, se identifica de inmediato que el algoritmo menos eficiente es el Bubble Sort, ya que su complejidad 𝑂(𝑛^2)
 ) lo hace inviable para grandes volúmenes de datos. En contraste, el algoritmo Quick Sort se posiciona como el más eficiente en términos generales. Sin embargo, en la gráfica se aprecia que Merge Sort y Shell Sort también presentan un rendimiento competitivo.

La eficiencia de estos tres últimos radica en que su complejidad temporal sigue un comportamiento de 𝑂(𝑛log𝑛), lo que les permite manejar grandes volúmenes de datos de manera mucho más óptima que los algoritmos cuadráticos como Burbuja e Inserción. No obstante, es importante considerar que Merge Sort requiere memoria adicional debido a su proceso de fusión, mientras que Quick Sort puede presentar un peor caso de 𝑂(𝑛^2) si el pivote no se elige correctamente.




**CONCLUSIONES**
Podemos concluir que el algoritmo de Bubble Sort no es una opción eficiente para ordenar grandes volúmenes de datos, aunque es útil como herramienta didáctica para comprender los fundamentos del ordenamiento.

Por otro lado, algoritmos como Quick Sort, Merge Sort y Shell Sort ofrecen una mejor eficiencia en la mayoría de los casos, siendo opciones más adecuadas para aplicaciones prácticas. La elección del algoritmo adecuado dependerá de varios factores, como:

El tamaño de la lista: Algoritmos cuadráticos pueden funcionar en listas pequeñas, pero no en listas grandes.

La necesidad de estabilidad: Merge Sort es estable, mientras que Quick Sort no lo es en todas sus implementaciones.

El consumo de memoria: Merge Sort requiere más espacio, mientras que Heap Sort y Quick Sort son más eficientes en este aspecto.

No existe un único algoritmo perfecto para todas las situaciones. La selección del método de ordenamiento debe basarse en las necesidades específicas del problema, considerando tiempo de ejecución, consumo de memoria y estabilidad. Comprender estos factores permite tomar decisiones más informadas y optimizar el rendimiento en distintos escenarios.

