#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <limits> // Para usar numeric_limits


const int INF = numeric_limits<int>::max(); // Definición de INF

class LoadBalancer {
private:
    int numServers;
    vector<vector<int>> adjMatrix;
    vector<int> requestPerServer;

public:
    LoadBalancer(int n, const vector<vector<int>>& matrix);
    int distributeRequest(int startServer);
    void completeRequest();
    void displayServerLoads();
};

#endif // LOADBALANCER_H
