#include "binary_search.h"
#include <iostream>
#include <vector>

using namespace std;

// Definición de la función binarySearch
int binarySearch(vector<int> vec, int target) {
    int lo = 0;
    int hi = vec.size() - 1;

    while (lo <= hi) { // Corregí la condición de bucle
        int mid = lo + (hi - lo) / 2;
        
        // Caso base
        if (vec[mid] == target) {
            return mid;
        }

        if (vec[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};  // Ejemplo de datos en el vector
    int target = 45;

    int index = binarySearch(vec, target);

    if (index != -1) {
        cout << "Elemento encontrado en el índice: " << index;
    } else {
        cout << "Elemento no encontrado";
    }

    return 0;
}
