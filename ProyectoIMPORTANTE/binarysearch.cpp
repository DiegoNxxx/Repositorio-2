#include <iostream>
#include <vector>
#include "BINARYSEARCH.h"

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


