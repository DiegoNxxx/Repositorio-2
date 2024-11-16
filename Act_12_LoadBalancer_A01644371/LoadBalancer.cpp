//
// Created by Diego Núñez on 11/11/24.
//

#include "LoadBalancer.h"
#include <iostream>

using namespace std;


LoadBalancer::LoadBalancer(int n, const vector<vector<int>>& matrix, int maxRequests)
: numServers(n), adjMatrix(matrix), requestsPerServer(n, 0), maxRequestsPerServer(maxRequests) {}





int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1 ;

     for (int i = 0; i < numServers; ++i) {
        if (i != startServer && adjMatrix[startServer][i] != INF) {
            // Verificamos que el servidor tenga capacidad para una solicitud adicional
            if (requestsPerServer[i] < maxRequestsPerServer) {
                // Si el servidor tiene menos carga que el seleccionado o no hay servidor seleccionado,
                // o si el costo de conexión es menor, seleccionamos este servidor.
                if (selectedServer == -1 || requestsPerServer[i] < requestsPerServer[selectedServer] ||
                    adjMatrix[startServer][i] < minCost) {
                    minCost = adjMatrix[startServer][i];
                    selectedServer = i;
                }
            }
        }
    }

    if (selectedServer != -1) {
        requestsPerServer[selectedServer]++;
        cout << "Solicitud asignada al Servidor " << selectedServer
                  << " desde Servidor " << startServer << ", Carga actual: "
                  << requestsPerServer[selectedServer] << "\n";
    } else {
        cout << "No hay servidores disponibles desde el Servidor " << startServer << "\n";
    }
    return selectedServer;

}

void LoadBalancer::completeRequest(int serverId) {
    // Se valida que el servidor exista y que exista dentro de los servidores inicializados
    // o que el servidor tenga al menos 1 solicitud
    if(serverId < 0 || serverId >= numServers || requestsPerServer[serverId] == 0) {
        cout << "Error: no hay solicitudes activas en el Servidor " << serverId << "\n";
        return;
    }

    requestsPerServer[serverId]--;
    std::cout << "Solicitud completada en el Servidor " << serverId
             << ", Carga actual: " << requestsPerServer[serverId] << "\n";
}

void LoadBalancer::displayServerLoads() {
    std::cout << "Cargas actuales de los servidores:\n";
    for (int i = 0; i < numServers; ++i) {
        std::cout << "Servidor " << i << ": " << requestsPerServer[i] << " solicitudes\n";
    }
}



