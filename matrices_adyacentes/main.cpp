#include <iostream>
#include <vector>
#include <limits> // Para INF
using namespace std;

const int INF = numeric_limits<int>::max(); // Definición de INF

int main() {
    int numServers = 4;

    vector<vector<int>> matrix = {
        {0, 10, 3, INF}, 
        {10, 0, 1, 2}, 
        {3, 1, 0, 8}, 
        {INF, 2, 8, 9}
    };

    // Ejemplo básico de verificación
    cout << "Número de servidores: " << numServers << endl;

    return 0;
}
