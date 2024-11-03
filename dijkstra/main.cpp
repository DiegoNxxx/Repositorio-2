#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm> // Para reverse

using namespace std;

const int INF = numeric_limits<int>::max();

// Función de Dijkstra modificada para mostrar el camino paso a paso
vector<int> dijkstra(int n, int origen, int destino, const vector<vector<pair<int, int>>>& grafo) {
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

int main() {
    int n = 7; // Número de nodos en el grafo
    vector<vector<pair<int, int>>> grafo(n);

    // Nodo 0 (Ejemplo: "A")
    grafo[0].push_back({1, 260}); // A-B
    grafo[0].push_back({2, 220});  // A-C
    // Nodo 1 (Ejemplo: "B")
    grafo[1].push_back({3, 550});  // B-D
    // Nodo 2 (Ejemplo: "C")
    grafo[2].push_back({3, 600});  // C-D
    // Nodo 3 (Ejemplo: "D")
    grafo[3].push_back({4, 750});  // D-E
    grafo[3].push_back({5, 800});  // D-F
    // Nodo 4 (Ejemplo: "E")
    grafo[4].push_back({6, 650});  // E-G
    // Nodo 5 (Ejemplo: "F")
    grafo[5].push_back({6, 700});  // F-G 

    int origen = 0;  // nodo de inicio deseado
    int destino = 6; // nodo de destino deseado 

    vector<int> camino = dijkstra(n, origen, destino, grafo);

    // Imprimir el camino y la distancia total
    cout << "Camino desde " << origen << " hasta " << destino << ": ";
    int distancia_total = 0;
    for (size_t i = 0; i < camino.size(); ++i) {
        cout << camino[i];
        if (i < camino.size() - 1) {
            // Sumar la distancia entre nodos consecutivos en el camino
            for (const auto& vecino : grafo[camino[i]]) {
                if (vecino.first == camino[i + 1]) {
                    distancia_total += vecino.second;
                    break;
                }
            }
            cout << " -> ";
        }
    }
    
    cout << "\nDistancia total: " << distancia_total << " metros" << endl;

    return 0;
}
