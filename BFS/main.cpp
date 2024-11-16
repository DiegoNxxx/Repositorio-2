#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <cstdlib> // Para rand()
using namespace std;

struct Person {
    string firstName;
    string lastName;
    string address;
    string city;
    string dna;
    string phone;
};

// Función para agregar una conexión en el grafo
void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

// Algoritmo BFS para buscar en el grafo
bool BFS(vector<vector<int>> &adj, const vector<Person> &people, const string &targetADN) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                // Verificar si la persona tiene el ADN buscado
                if (people[current].dna == targetADN) {
                    cout << "Persona encontrada: " << people[current].firstName << " " << people[current].lastName
                         << ", Direccion: " << people[current].address
                         << ", Ciudad: " << people[current].city
                         << ", Codigo Genetico: " << people[current].dna
                         << ", Telefono: " << people[current].phone << endl;
                    return true; // Encontrado
                }

                // Explorar nodos adyacentes
                for (int neighbor : adj[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return false; // No encontrado
}

// Función principal
int main() {
    ifstream file("people.txt");
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    vector<Person> people;
    string line;

    // Leer datos del archivo y almacenar en el vector people
    while (getline(file, line)) {
        stringstream ss(line);
        Person person;
        getline(ss, person.firstName, ',');
        getline(ss, person.lastName, ',');
        getline(ss, person.address, ',');
        getline(ss, person.dna, ',');
        getline(ss, person.city, ',');
        getline(ss, person.phone, ',');
        people.push_back(person);
    }
    file.close();

    int V = people.size();
    vector<vector<int>> adj(V);

    // Crear conexiones aleatorias entre nodos
    srand(time(0)); // Semilla aleatoria
    for (int i = 0; i < V; i++) {
        int connections = rand() % 5 + 1; // Entre 1 y 5 conexiones por nodo
        for (int j = 0; j < connections; j++) {
            int target = rand() % V;
            if (target != i) { // Evitar lazo a sí mismo
                addEdge(adj, i, target);
            }
        }
    }

    // ADN objetivo para la búsqueda
    string targetADN;
    cout << "Ingrese el codigo genetico deseado : ";
    cin >> targetADN;

    // Medir el tiempo de ejecución de BFS
    auto start = chrono::high_resolution_clock::now();
    bool found = BFS(adj, people, targetADN);
    auto end = chrono::high_resolution_clock::now();

    // Mostrar resultados
    if (!found) {
        cout << "No se encontro ninguna persona con ese codigo." << endl;
    }

    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecucion de BFS: " << elapsed.count() << " segundos." << endl;

    return 0;
}
