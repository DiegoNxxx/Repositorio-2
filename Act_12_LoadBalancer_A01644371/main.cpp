// Diego Núñez García A01644371

#include <iostream>
#include <vector>
#include <cstdlib>   // Para srand y rand
#include <ctime>     // Para time
#include "LoadBalancer.h"

int main() {
    int numServers;
    int maxRequestsPerServer;

    std::cout << "Ingrese el numero de servidores: ";
    std::cin >> numServers;

    std::cout << "Ingrese el limite máximo de peticiones por servidor: ";
    std::cin >> maxRequestsPerServer;

    // Inicializamos la semilla para generar números aleatorios
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generar una matriz de tamaño numServers x numServers con valores aleatorios entre 1 y 10
    std::vector<std::vector<int>> matrix(numServers, std::vector<int>(numServers));
    for (int i = 0; i < numServers; ++i) {
        for (int j = 0; j < numServers; ++j) {
            if (i == j) {
                matrix[i][j] = 0; // Diagonal principal en cero
            } else {
                matrix[i][j] = (std::rand() % 10) + 1; // Número aleatorio entre 1 y 10
            }
        }
    }

    // Mostrar la matriz generada (opcional, para verificar)
    std::cout << "Matriz generada:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            if (value == INF) {
                std::cout << "INF ";
            } else {
                std::cout << value << " ";
            }
        }
        std::cout << "\n";
    }

    // Crear la instancia de LoadBalancer con los parámetros adecuados
    LoadBalancer lb(numServers, matrix, maxRequestsPerServer);

    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoads();

    return 0;
}
