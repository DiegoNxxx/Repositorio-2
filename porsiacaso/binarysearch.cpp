#include <iostream>
#include <vector>
#include "BINARYSEARCH.h"
#include <queue>
#include <limits>
#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>
#include "BINARYSEARCH.h"
#include "STACK.h"
#include <queue>
#include <limits>
#include <algorithm> 
#include "GraphBFS.h"
#include "GraphDFS.h"
#include "LoadBalancer.h"
#include "Node.h"
#include "Queue.h"


using namespace std;

int binarySearch(vector<int> vec, int target){
    for (int numero : vec) {
        if (numero > target) {
            return numero;
        }
    }
    return -1; 
}

void bubbleSort(vector<int> &vec) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(vec[j] > vec[j+1]) {
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

void mySwap( int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> & vec){
    int n = vec.size();

    for(int i=0; i< n-1; i++){
        for(int j= i+1; j < n; j++){
            int minVal = i;
            for(int j= i+1; j < n; j++){
                if(vec[j] < vec[minVal]){
                    minVal =j;
                }
            }
            if(minVal != i){
                mySwap(vec[i], vec[minVal]);
            }
        } 
    }

}

void eliminarNoPrimos(vector<int>& numeros) {
    vector<int> primos;

    for (int num : numeros) {
        if (NumeroPrimo(num)) {
            primos.push_back(num); // regresa los primos nomas
        }
    }
    numeros = primos;
}

bool NumeroPrimo(int num) { // bool para que sean valores de verdadero y falso 
    for (int i = 2; i < num; ++i) { 
        if (num % i == 0) return false; // Si es divisible por i, no es primo
    }
        if (num ==2) return false;
        
    return true; 
}

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array){

    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    // indices que asen cosas asi chidas
    int i = 0;
    int l = 0;
    int r = 0;

    //main loop
    while (l < leftSize && r <rightSize)
    {
        if(leftArray[l] < rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        } else{
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
    
    while (l< leftSize)
    {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize)
    {
        array[i] = rightArray[r];
        i++;
        r++;
    }
    
    
}

void mergeSort(vector<int>& array){

    int n = array.size();
    if(n<=1) return; //  caso base
    int center = n/2;

    vector<int> leftArray(center);
    vector<int> rightArray(n - center);

    // crear arreglo izquierdo con el size inicial en el lenght del array
    for(int i = 0; i<n; i++){
        if(i<center){
            leftArray[i]=array[i];

        } else {
            rightArray[i- center] = array[i];
        }
    }

    // DIVIDE
    mergeSort(leftArray);
    mergeSort(rightArray);
    // CONQUER
    merge(leftArray, rightArray, array);
}

int partition(vector<int>& arr, int low, int high) {
  

    int pivot = arr[high];
  

    int i = low - 1;


    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

struct Node {
    int data;
    Node* next;
};


// Función para agregar un nodo al final de la lista
void addNode(Node*& head, int value) {
    Node* newNode = new Node(); // Crear un nuevo nodo en memoria
    newNode->data = value;      // Asignar el valor al nodo
    newNode->next = nullptr;    // El siguiente nodo es nullptr

    if (head == nullptr) {
        head = newNode; // Si la lista está vacía, el nuevo nodo es la cabeza
    } else {
        Node* temp = head;
        // Recorrer la lista hasta el último nodo
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; // Enlazar el nuevo nodo al final
    }
}

void showList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


Queue::Queue(int capacity) {
    front = -1;
    rear = -1;
    size = capacity;
    queue = new int[size];
}

bool Queue::isEmpty() {
    return (front == -1);
}

bool Queue::isFull() {
    return (rear == size - 1);
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "La Queue está llena." << endl;
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    
    queue[++rear] = value;
    cout << value << " añadido a la queue." << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "La Queue está vacía." << endl;
        return;
    }

    cout << queue[front] << " removido de la front." << endl;
    front++;
    
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

int Queue::frontElement() {
    if (isEmpty()) {
        cout << "La Queue está vacía. No hay elemento en el front." << endl;
        return -1;
    }
    
    return queue[front];
}

Queue::~Queue() {
    delete[] queue;
}

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


// Constructor de la clase
LoadBalancer::LoadBalancer(int n, const vector<vector<int>> &matrix) : numServers(n), adjMatrix(matrix), requestPerServer(n, 0) {}

int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1;

    for (int i = 0; i < numServers; i++) {
        if (i != startServer && adjMatrix[startServer][i] != INF) {
            if ((selectedServer == -1 || requestPerServer[i] < requestPerServer[selectedServer])
                && (adjMatrix[startServer][i] < minCost)) {
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
            }
        }
    }

    if (selectedServer != -1) {
        requestPerServer[selectedServer]++;
        cout << "Solicitud asignada al servidor: " << selectedServer << endl;
    } else {
        cout << "No hay servidores disponibles desde el servidor: " << startServer << endl;
    }

    return selectedServer;
}

void LoadBalancer::displayServerLoads() {
    cout << "\n--- Carga actual de los servidores ---\n";
    for (int i = 0; i < numServers; i++) {
        cout << "Servidor " << i << ": " << requestPerServer[i] << " solicitudes\n";
    }
}

GraphDFS::GraphDFS(int vertices) : numVertices(vertices) {
    adjList.resize(vertices);
}

void GraphDFS::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // Para grafo no dirigido
}

void GraphDFS::dfsUtil(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited);
        }
    }
}

GraphDFS::GraphDFS(int vertices) : numVertices(vertices) {
    adjList.resize(vertices);
}

void GraphDFS::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // Para grafo no dirigido
}

void GraphDFS::dfsUtil(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited);
        }
    }
}

void GraphDFS::dfs(int startVertex) {
    vector<bool> visited(numVertices, false);
    cout << "DFS desde el nodo " << startVertex << ": ";
    dfsUtil(startVertex, visited);
    cout << endl;
}



void GraphDFS::dfs(int startVertex) {
    vector<bool> visited(numVertices, false);
    cout << "DFS desde el nodo " << startVertex << ": ";
    dfsUtil(startVertex, visited);
    cout << endl;
}