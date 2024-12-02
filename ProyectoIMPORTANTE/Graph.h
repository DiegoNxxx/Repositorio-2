#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix; // Matriz de adyacencia
    int numVertices;

    void dfsUtil(int vertex, vector<bool>& visited) {
        cout << vertex << " ";
        visited[vertex] = true;

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[vertex][i] && !visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Para grafo dirigido
        adjMatrix[v][u] = 1; // Si es no dirigido
    }

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS desde el nodo " << startVertex << ": ";
        dfsUtil(startVertex, visited);
        cout << endl;
    }

    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS desde el nodo " << startVertex << ": ";
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[vertex][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

#endif // GRAPH_H
