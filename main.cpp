/*
 * Programa Divide y Vencerás con Búsqueda Binaria
 * Emiliano Carrizales Becerra A00824311
 * Fecha: 21 de febrero del 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>


/*
 * Función que busca un valor entero dentro de un arreglo en el índice en que se encuentra
 * @param array El array de enteros
 * @param start Index inicial donde empieza el rango de búsqueda
 * @param end Index del final de rango de búsqueda
 * @param target El valor entero que se busca
 * @param return Index donde se encuentra el entero o -1 si no se encuentra
 * Complejidad: O(log n)
 */
int binary_search(const std::vector<int>& array, int start, int end, int target) {

    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (array[mid] == target) {
        return mid;
    }

    if (array[mid] > target) {
        return binarySearch(array, start,  mid - 1, target);
    }

    return binarySearch(array, mid + 1, end, target);
}

/*
 * Ordena el array de menor a mayor y ejecuta la búsqueda
 * @param data Copia del array
 * @param search Valor entero que se busca
 * return void
 */
void printArray(std::vector<int> data, int search) {

    std::sort(data.begin(), data.end());

    std::cout << "Array ordenado de menor a mayor\n";

    for (int num : data) std::cout << num << " ";

    std::cout << "Buscando: " << search << std::endl;

    int result = binarySearch(data, 0, data.size() - 1, search);

    if (result != -1) {
        std::cout << "Número encontrado en índice: " << result << "\n";
    } else {
        std::cout << "Número no encontrado (-1)\n";
    }
}

int main() {

    std::cout << "\nPrimer caso \n";
    printArray({8, 3, 10, -1, 6, 14, 4}, 6);

    std::cout << "\nSegundo caso \n";
    printArray({2, 4, 6, 8, 10}, 7);

    std::cout << "\nTercer caso \n";
    printArray({42}, 42);

    std::cout << "\nCuarto caso \n";
    printArray({5, 3, 7, 3, 9, 3, 1}, 7);

    return 0;
}
