#ifndef GRAPHDFS_H
#define GRAPHDFS_H

#include <vector>
#include <iostream>


class GraphDFS {
private:
    int numVertices;
    vector<vector<int>> adjList;
    void dfsUtil(int vertex, vector<bool>& visited);
    
public:
    GraphDFS(int vertices);
    void addEdge(int src, int dest);
    void dfs(int startVertex);
};

#endif // GRAPHDFS_H
