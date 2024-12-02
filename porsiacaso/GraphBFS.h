#ifndef GRAPHBFS_H
#define GRAPHBFS_H

#include <vector>
#include <queue>
#include <iostream>
#include <limits>


class GraphBFS {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    GraphBFS(int vertices);
    void addEdge(int src, int dest);
    void bfs(int startVertex);
    
    // Declaración de la función Dijkstra
    vector<int> dijkstra(int n, int origen, int destino, const vector<vector<pair<int, int>>>& grafo);
};

#endif // GRAPHBFS_H