#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

// Búsqueda DFS recursiva
bool DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s, const vector<Person> &people, const string &targetADN) {
    visited[s] = true;

    // Verificar si la persona tiene el número de teléfono buscado
    if (people[s].dna == targetADN) {
        cout << "Persona encontrada: " << people[s].firstName << " " << people[s].lastName
             << ", Direccion: " << people[s].address
             << ", Ciudad: " << people[s].city
             << ", Codigo Genetico: " << people[s].dna
             << ", Telefono: " << people[s].phone << endl;
        return true; // Encontrado
    }

    // Recorrer nodos adyacentes
    for (int i : adj[s]) {
        if (!visited[i]) {
            if (DFSRec(adj, visited, i, people, targetADN))
                return true; // Detener búsqueda si ya se encontró
        }
    }
    return false; // No encontrado
}

// Algoritmo DFS principal
bool DFS(vector<vector<int>> &adj, const vector<Person> &people, const string &targetADN) {
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            if (DFSRec(adj, visited, i, people, targetADN))
                return true;
        }
    }
    return false; // Teléfono no encontrado
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

    // Número de teléfono objetivo para la búsqueda
    string targetADN;
    cout << "Ingrese el codigo genetico deseado : ";
    cin >> targetADN;

    // Medir el tiempo de ejecución de DFS
    auto start = chrono::high_resolution_clock::now();
    bool found = DFS(adj, people, targetADN);
    auto end = chrono::high_resolution_clock::now();

    // Mostrar resultados
    if (!found) {
        cout << "No se encontro ninguna persona con ese codigo." << endl;
    }

    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecucion de DFS: " << elapsed.count() << " segundos." << endl;

    return 0;
}