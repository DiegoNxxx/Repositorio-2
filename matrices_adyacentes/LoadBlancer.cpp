#include "LoadBalancer.h"
using namespace std;
#include <iostream>


LoadBalancer::LoadBalancer(int n, const vector<vector<int>> &matrix):numServers(n), adjMatrix(matrix), requestPerServer(n, 0) {};

int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1;

    for(int i = 0; i < numServers; i++) {
        if(i != startServer && adjMatrix[startServer][i] != INF){
            if((requestPerServer[i] < requestPerServer[selectedServer] || selectedServer != -1)
                && (adjMatrix[startServer][i] < minCost)
            ) {
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
            }
        }
    }

    if(selectedServer !== -1) {
        requestPerServer[selectedServer]++;
        cout << "Solicitud asignada al servidor :" << selectedServer;
    } else {
        cout << "No hay servidores disponibles:" << startServer;
    }

    return selectedServer;


}