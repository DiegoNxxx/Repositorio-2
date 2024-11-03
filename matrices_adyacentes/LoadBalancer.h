#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <vector>
#include <iostream>
using namespace std;

const int INF = Int_max;

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