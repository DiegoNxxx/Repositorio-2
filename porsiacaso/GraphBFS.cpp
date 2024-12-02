#include "GraphBFS.h"
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>  // Para usar reverse()

const int INF = numeric_limits<int>::max();

vector<int> GraphBFS::dijkstra(int n, int origen, int destino, const vector<vector<pair<int, int>>>& grafo) {
    vector<int> distancias(n, INF); // Inicializa todas las distancias en "infinito"
    vector<int> predecesores(n, -1); // Para rastrear el camino
    distancias[origen] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        int distancia_actual = pq.top().first;
        int nodo_actual = pq.top().second;
        pq.pop();

        if (nodo_actual == destino) break; // Termina si alcanzamos el destino

        if (distancia_actual > distancias[nodo_actual]) continue;

        for (const auto& vecino : grafo[nodo_actual]) {
            int nodo_vecino = vecino.first;
            int peso_arista = vecino.second;

            int nueva_distancia = distancia_actual + peso_arista;

            if (nueva_distancia < distancias[nodo_vecino]) {
                distancias[nodo_vecino] = nueva_distancia;
                predecesores[nodo_vecino] = nodo_actual;
                pq.push({nueva_distancia, nodo_vecino});
            }
        }
    }

    // Construir el camino de regreso usando el vector de predecesores
    vector<int> camino;
    for (int v = destino; v != -1; v = predecesores[v]) {
        camino.push_back(v);
    }
    reverse(camino.begin(), camino.end()); // Invertir el camino para que inicie en el origen

    return camino;
}
