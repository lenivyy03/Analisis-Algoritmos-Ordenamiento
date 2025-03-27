#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <string>

// Constantes globales
const int NUM_PRUEBAS = 1000;
const int MIN_TAMANO = 10;
const int MAX_TAMANO = 1000;
const int INCREMENTO = 10;

// ------------------------- ALGORITMOS DE ORDENAMIENTO -------------------------

// 1. Ordenamiento por Inserción
void insercionPorOrden(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

// 2. Ordenamiento Burbuja Optimizado
void ordenamientoBurbujaOptimizado(int arr[], int n) {
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

// 3. Ordenamiento por Selección
void ordenamientoPorSeleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

// 4. Merge Sort
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Shell Sort
void shellSort(std::vector<int>& arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ------------------------- FUNCIÓN PRINCIPAL -------------------------

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, MAX_TAMANO);

    // Vector para almacenar tiempos de cada algoritmo
    std::vector<std::vector<std::vector<double>>> todosTiempos(7, 
        std::vector<std::vector<double>>(MAX_TAMANO / INCREMENTO, 
        std::vector<double>(NUM_PRUEBAS)));

    // Nombres de los algoritmos y sus archivos CSV
    const std::vector<std::string> nombresAlgoritmos = {
        "Insercion", "Burbuja", "Seleccion", 
        "Mezcla", "Rapido", "Monticulos", "Shell"
    };

    // Bucle principal para todos los tamaños
    for (int tamano = MIN_TAMANO, idx = 0; tamano <= MAX_TAMANO; tamano += INCREMENTO, ++idx) {
        std::cout << "Procesando tamano: " << tamano << std::endl;
        
        for (int rep = 0; rep < NUM_PRUEBAS; ++rep) {
            // Generar arreglo original
            std::vector<int> arrOriginal(tamano);
            for (int i = 0; i < tamano; ++i) {
                arrOriginal[i] = dis(gen);
            }

            // 1. Inserción
            {
                int* arr = new int[tamano];
                std::copy(arrOriginal.begin(), arrOriginal.end(), arr);
                auto inicio = std::chrono::high_resolution_clock::now();
                insercionPorOrden(arr, tamano);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[0][idx][rep] = duracion.count();
                delete[] arr;
            }

            // 2. Burbuja
            {
                int* arr = new int[tamano];
                std::copy(arrOriginal.begin(), arrOriginal.end(), arr);
                auto inicio = std::chrono::high_resolution_clock::now();
                ordenamientoBurbujaOptimizado(arr, tamano);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[1][idx][rep] = duracion.count();
                delete[] arr;
            }

            // 3. Selección
            {
                int* arr = new int[tamano];
                std::copy(arrOriginal.begin(), arrOriginal.end(), arr);
                auto inicio = std::chrono::high_resolution_clock::now();
                ordenamientoPorSeleccion(arr, tamano);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[2][idx][rep] = duracion.count();
                delete[] arr;
            }

            // 4. Merge Sort
            {
                std::vector<int> arr = arrOriginal;
                auto inicio = std::chrono::high_resolution_clock::now();
                mergeSort(arr, 0, tamano - 1);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[3][idx][rep] = duracion.count();
            }

            // 5. Quick Sort
            {
                std::vector<int> arr = arrOriginal;
                auto inicio = std::chrono::high_resolution_clock::now();
                quickSort(arr, 0, tamano - 1);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[4][idx][rep] = duracion.count();
            }

            // 6. Heap Sort
            {
                std::vector<int> arr = arrOriginal;
                auto inicio = std::chrono::high_resolution_clock::now();
                heapSort(arr, tamano);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[5][idx][rep] = duracion.count();
            }

            // 7. Shell Sort
            {
                std::vector<int> arr = arrOriginal;
                auto inicio = std::chrono::high_resolution_clock::now();
                shellSort(arr, tamano);
                auto fin = std::chrono::high_resolution_clock::now();
                auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
                todosTiempos[6][idx][rep] = duracion.count();
            }
        }
    }

    // Generar archivos CSV para cada algoritmo
    for (int algo = 0; algo < 7; ++algo) {
        std::string filename = std::to_string(algo + 1) + "_Ordenamiento_" + nombresAlgoritmos[algo] + "_tiempos.csv";
        std::ofstream csvFile(filename);
        
        // Encabezados
        for (int tamano = MIN_TAMANO; tamano <= MAX_TAMANO; tamano += INCREMENTO) {
            csvFile << "Tamano " << tamano << (tamano < MAX_TAMANO ? "," : "\n");
        }
        
        // Datos
        for (int rep = 0; rep < NUM_PRUEBAS; ++rep) {
            for (size_t idx = 0; idx < todosTiempos[algo].size(); ++idx) {
                csvFile << todosTiempos[algo][idx][rep] << (idx < todosTiempos[algo].size() - 1 ? "," : "\n");
            }
        }
        
        csvFile.close();
        
        // Calcular y mostrar promedios
        std::cout << "\nTiempos promedio para " << nombresAlgoritmos[algo] << ":\n";
        for (int tamano = MIN_TAMANO, idx = 0; tamano <= MAX_TAMANO; tamano += INCREMENTO, ++idx) {
            double suma = std::accumulate(todosTiempos[algo][idx].begin(), todosTiempos[algo][idx].end(), 0.0);
            double promedio = suma / NUM_PRUEBAS;
            std::cout << "Tamano " << tamano << ": " << promedio << " ns\n";
        }
    }

    return 0;
}