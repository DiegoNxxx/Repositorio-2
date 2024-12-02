#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <algorithm> 
#include "STACK.h"
#include "Queue.h"
#include "User.h"
#include "AVLTree.h"
#include "Graph.h"

using namespace std;
// Variables
int continuar = 1, opcion, N;
const int INF = numeric_limits<int>::max();

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

// Declaración de funciones
int binarySearch(vector<int>& vec, int target) {
    sort(vec.begin(), vec.end());  // Ordenar el arreglo antes de buscar
    int left = 0, right = vec.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (vec[mid] == target) {
            return mid;  // Retorna el índice si se encuentra el número
        }
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Si no se encuentra el número
}
void bubbleSort(vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
             if(vec[j] > vec[j+1]){
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
bool NumeroPrimo(int num) { // bool para que sean valores de verdadero y falso 
    for (int i = 2; i < num; ++i) { 
        if (num % i == 0) return false; // Si es divisible por i, no es primo
    }
        if (num ==2) return false;
        
    return true; 
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
void insertionSort(vector<int>& arr){
    int n = arr.size();


    for (int i =1; i < n; i++){
        int key = arr[i];
        int j= i-1;

        while (j >= 0 && arr[j]> key)
        {
            arr[j+1]= arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    
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
void addNode(Node* &head, int value) {
    Node* newNode = new Node(); // Crear un nuevo nodo en memoria
    newNode -> data = value; // Asignacion de value a la estructura accediendo a data
    newNode -> next = nullptr; // el siguiente nodo es nullptr

    if(head == nullptr) {
        head = newNode; // si la lista esta vacia el nuevo nodo es la head
    } else {
        Node* temp = head; // crear una variable temporal que almacene el current head
        // recorremos la lista hasta el ultimo nodo
        while(temp->next != nullptr) {
            temp=temp->next;
        }
        temp->next = newNode; // enlazamos
    }
}
void showList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "-> ";
        temp= temp -> next;
    }
}
void imprimirMatriz(const vector<vector<int>>& matriz) {
    cout << "Matriz de adyacencia:" << endl;
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            if (valor == INF)
                cout << "INF ";
            else
                cout << valor << " ";
        }
        cout << endl;
    }
}


int main() {


    while (continuar) {
        // Mostrar el menú
        cout << "\n--- Menú de opciones ---" << endl;
        cout << "1. BinarySearch" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Linked List" << endl;
        cout << "8. Stacks" << endl;
        cout << "9. Queue" << endl;
        cout << "10. AVL" << endl;
        cout << "11. Dijkstra" << endl;
        cout << "12. Matrices Adyac." << endl;
        cout << "13. BFS" << endl;
        cout << "14. DFS" << endl;

        cout << "15. Salir" << endl;
        
        cout << "\nSeleccione una opción: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada usando switch
        switch (opcion) {
           case 1: { // BinarySearch
                int target;
                vector<int> data;
                cout << "Seleccionaste la opción 1: BinarySearch\n";
                cout << "¿Cuántos números quieres ingresar? ";
                cin >> N;
                for (int i = 0; i < N; ++i) {
                    int num;
                    cout << "Número " << i + 1 << ": ";
                    cin >> num;
                    data.push_back(num);
                }
                cout << "Ingresa el número objetivo: ";
                cin >> target;
                
                // Realizar la búsqueda
                int result = binarySearch(data, target);
                if (result != -1) {
                    cout << "Elemento encontrado en el índice: " << result << endl;
                } else {
                    cout << "Elemento no encontrado." << endl;
                }
                break;
            }
            case 2: {  //BubbleSorte
                vector<int> data;
                data.clear();
                cout << "Seleccionaste la opción 2: Bubble Sort\n";
                cout << "¿Cuántos números quieres ordenar? ";
                cin >> N;
                for (int i = 0; i < N; i++) {
                    int temp;
                    cout << "Número " << i + 1 << ": ";
                    cin >> temp;
                    data.push_back(temp);
                }
                bubbleSort(data);
                cout << "Números ordenados: ";
                for (int num : data) cout << num << " ";
                cout << endl;
                break;

            }
            case 3:{ //Selection Sort
            vector<int> data;
            cout << "Seleccionó Selection Sort";
            cout << "Ingresa la cantidad de números a ordenar: ";
                cin >> N;
                for (int i = 0; i < N; i++) {
                    cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                    cin >> data[i];
                }

                // Ordenar el vector usando Selection Sort
                selectionSort(data);

                // Mostrar los números ordenados
                cout << "Números ordenados: ";
                for (int num : data) {
                    cout << num << " ";
                }
                cout << endl;
                        
                    break;
            }
            case 4:{  //Insertion Sort
                vector<int> data;
                cout << "Seleccionaste la opcion 4: Insertion Sort" << endl;
                cout << "Ingresa la cantidad de números a ordenar: ";
                cin >> N;
                for (int i = 0; i < N; i++) {
                int temp;
                cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                cin >> temp;
                data.push_back(temp);
                }
                // Ordenar usando Insertion Sort
                insertionSort(data);        
                // Eliminar números que no son primos
                eliminarNoPrimos(data);
                // Mostrar los números primos ordenados
                cout << "Números primos ordenados: ";
                for (int num : data) {
                    cout << num << " ";
                }
                cout << endl;
                    break;

            }
            case 5:{ // Merge Sort
                vector<int> array;
                cout << "Seleccionaste la opcion 5: Merge Sort" << endl;
                cout << "Ingresa la cantidad de números a ordenar: ";
                cin >> N;
                // Leer los números del usuario
                for (int i = 0; i < N; i++) {
                    int temp;
                    cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                    cin >> temp;
                    array.push_back(temp);
                }
                    // Ordenar el arreglo usando Merge Sort
                mergeSort(array);
                    // Mostrar los números ordenados
                cout << "Números ordenados: ";
                for (int num : array) {
                    cout << num << " ";
                }
                cout << endl;
                    break;


            }
            case 6: { // Quick Sort
                vector<int> array;
                cout << "Seleccionaste la opcion 7: Quick Sort" << endl;
                 // Simulación del menú interactivo: QuickSort
                cout << "Ingresa la cantidad de números a ordenar: ";
                cin >> N;
                // Leer los números del usuario
                for (int i = 0; i < N; i++) {
                    int temp;
                    cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                    cin >> temp;
                    array.push_back(temp);
                }
                // Aplicar QuickSort al arreglo
                quickSort(array, 0, N - 1);
                 // Mostrar los números ordenados
                cout << "Números ordenados: ";
                for (int num : array) {
                    cout << num << " ";
                }
                cout << endl;
                            
                break;

            }
            case 7: { // Linked List
                Node* list  = nullptr;
                cout << "Seleccionaste la opcion 7: Linked List" << endl;
                cout << "Ingresa la cantidad de valores a agregar en la lista: ";
                cin >> N;
                int value;
                for (int i = 0; i < N; i++) {
                    cout << "Ingresa el valor " << i + 1 << ": ";
                    cin >> value;
                    addNode(list, value);
                }
                // Mostrar la lista completa
                cout << "Lista de valores: ";
                showList(list);
                break;

            }
            case 8: { // Stacks
                cout << "Seleccionaste la opcion 9: Stacks" << endl;
                Stack stack;
                stack.push(30);
                stack.push(50);
                stack.push(70);

                cout << "El elemento top es: " << stack.top() << endl;
                stack.pop();
                cout << "Después del pop, el elemento top es: " << stack.top() << endl;

                break;
            }
            case 9: { // Queue

                    int option, value;
                    Queue q(5);
                    cout << "\nOperaciones de Queue:\n";
                    cout << "1. Enqueue\n2. Dequeue\n3. Mostrar frente\n4. Salir\n";
                    cout << "Opción: ";
                    cin >> option;
                    switch (option) {
                        case 1:
                            cout << "Ingresa el valor a agregar: ";
                            cin >> value;
                            q.enqueue(value);
                            break;
                        case 2:
                            q.dequeue();
                            break;
                        case 3:
                            cout << "Elemento al frente: " << q.frontElement() << endl;
                            break;
                        default:
                            cout << "Opción inválida.\n";
                    }
 
                break;
                }
            case 10: { // AVL
    AVLTree tree;

    int option;
    User* user;
    int id;
    string name, email, joinDate;

    do {
        cout << "\nOperaciones de Árbol AVL:\n";
        cout << "1. Insertar Usuario\n";
        cout << "2. Eliminar Usuario\n";
        cout << "3. Mostrar Usuarios\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Ingresa el ID del usuario: ";
                cin >> id;
                cout << "Ingresa el nombre del usuario: ";
                cin >> name;
                cout << "Ingresa el correo electrónico del usuario: ";
                cin >> email;
                cout << "Ingresa la fecha de registro del usuario: ";
                cin >> joinDate;
                user = new User(id, name, email, joinDate);
                tree.root = tree.insert(tree.root, user);
                break;

            case 2:
                cout << "Ingresa el ID del usuario a eliminar: ";
                cin >> id;
                tree.deleteUser(tree.root, id);
                break;

            case 3:
                cout << "Usuarios almacenados en el árbol AVL:" << endl;
                tree.inorder(tree.root);
                break;

            default:
                cout << "Opción inválida.\n";
        }
    } while (option != 4);
                
            }
            case 11:{ // Dijstra
              // Leer el número de nodos
    int n;
    cout << "Ingresa el número de nodos en el grafo: ";
    cin >> n;

    // Inicializar el grafo
    vector<vector<pair<int, int>>> grafo(n);

    // Leer el número de aristas
    cout << "Ingresa el número de aristas: ";
    int num_aristas;
    cin >> num_aristas;

    // Leer las aristas
    for (int i = 0; i < num_aristas; ++i) {
        int u, v, peso;
        cout << "Arista " << i + 1 << " (origen destino peso): ";
        cin >> u >> v >> peso;
        grafo[u].push_back({v, peso});
    }

    // Leer nodo de origen y destino
    int origen, destino;
    cout << "Ingresa el nodo de origen: ";
    cin >> origen;
    cout << "Ingresa el nodo de destino: ";
    cin >> destino;

    // Llamar a Dijkstra
    vector<int> camino = dijkstra(n, origen, destino, grafo);

    // Mostrar el camino y la distancia total
    cout << "Camino desde " << origen << " hasta " << destino << ": ";
    int distancia_total = 0;
    for (size_t i = 0; i < camino.size(); ++i) {
        cout << camino[i];
        if (i < camino.size() - 1) {
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


            break;


            }
            case 12:{ // Matrices Adyac.
            cout << "Seleccionaste la opción: Operaciones con Matriz de Adyacencia" << endl;
            int numNodos;
            cout << "Ingresa el número de nodos en el grafo: ";
            cin >> numNodos;
            // Crear una matriz de adyacencia inicializada con INF
            vector<vector<int>> matriz(numNodos, vector<int>(numNodos, INF));
            // Leer las aristas
            int numAristas;
            cout << "Ingresa el número de aristas: ";
            cin >> numAristas;
            cout << "Ingresa las aristas en el formato (origen destino peso):" << endl;
                for (int i = 0; i < numAristas; ++i) {
                    int origen, destino, peso;
                    cout << "Arista " << i + 1 << ": ";
                    cin >> origen >> destino >> peso;
                    matriz[origen][destino] = peso;
                    matriz[destino][origen] = peso; // Si el grafo es no dirigido
                }
                // Mostrar la matriz de adyacencia
           imprimirMatriz(matriz);

              // Operación adicional: mostrar distancias mínimas desde un nodo específico
            int nodoOrigen;
            cout << "Ingresa el nodo de origen para calcular las distancias: ";
            cin >> nodoOrigen;

            cout << "Distancias desde el nodo " << nodoOrigen << ":" << endl;
            for (int i = 0; i < numNodos; ++i) {
                if (matriz[nodoOrigen][i] == INF)
                    cout << "INF ";
                else
                    cout << matriz[nodoOrigen][i] << " ";
            }
            cout << endl;

            }
            case 13:{
              int option;

    while (true) {
        cout << "\nMENU PRINCIPAL:\n";
        cout << "13. Operaciones con DFS y BFS\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> option;

        switch (option) {
            case 13: {
                int numVertices, startVertex, subOption;
                cout << "Seleccionaste la opción 13: BFS y DFS" << endl;
                cout << "Selecciona el número de nodos en el grafo: ";
                cin >> numVertices;

                // Crear el grafo
                Graph graph(numVertices);

                // Agregar algunas aristas de ejemplo
                graph.addEdge(0, 1);
                graph.addEdge(0, 2);
                graph.addEdge(1, 3);
                graph.addEdge(2, 4);

                // Submenú para DFS y BFS
                while (true) {
                    cout << "\n1. Ejecutar DFS\n";
                    cout << "2. Ejecutar BFS\n";
                    cout << "3. Volver al menú principal\n";
                    cout << "Selecciona una opción: ";
                    cin >> subOption;

                    switch (subOption) {
                        case 1:
                            cout << "Ingresa el nodo inicial para DFS: ";
                            cin >> startVertex;
                            if (startVertex >= 0 && startVertex < numVertices)
                                graph.dfs(startVertex);
                            else
                                cout << "Nodo inválido.\n";
                            break;

                        case 2:
                            cout << "Ingresa el nodo inicial para BFS: ";
                            cin >> startVertex;
                            if (startVertex >= 0 && startVertex < numVertices)
                                graph.bfs(startVertex);
                            else
                                cout << "Nodo inválido.\n";
                            break;

                        case 3:
                            cout << "Volviendo al menú principal...\n";
                            goto exit_submenu;

                        default:
                            cout << "Opción inválida, intenta de nuevo.\n";
                    }
                }
                exit_submenu:
                break;
            }

            case 0:
                cout << "Saliendo del programa...\n";
                return 0;

            default:
                cout << "Opción inválida, intenta de nuevo.\n";
        }
    }
            }
            
            case 15:{ 

                cout << "Saliendo...\n";
                continuar = false;
                break;

            default:
                cout << "Opción no válida. Por favor, ingresa un número entre 1 y 19." << endl;
        }

        }

        cout << endl; // Separador para mejor visualización
    }

    return 0;
}

