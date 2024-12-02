#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
using namespace std;

// Declaración de la función binarySearch
int binarySearch(vector<int> vec, int target);

void bubbleSort(vector<int> &vec);

void selectionSort(vector<int> & vec);

void insertionSort(vector<int>& arr);

void eliminarNoPrimos(vector<int>& numeros);

void mySwap( int& a, int& b);

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array);

void mergeSort(vector<int>& array);

int partition(vector<int>& arr, int low, int high);

void quickSort(vector<int>& arr, int low, int high);

void addNode(Node* &head, int value);

void showList(Node* head);


#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private: 
        int front;
        int rear; 
        int size;
        int* queue;

    public:
        Queue(int capacity);  // Constructor
        bool isEmpty();       // Verificar si está vacía
        bool isFull();        // Verificar si está llena
        void enqueue(int value);  // Agregar un elemento
        void dequeue();       // Remover un elemento
        int frontElement();   // Obtener el primer elemento
        ~Queue();             // Destructor
};

#endif

#ifndef USERAVL_H
#define USERAVL_H
#include <string>
using namespace std;



class User {
public:
    int id;
    string name;
    string email;
    string creationDate;

    User(int id, string name, string email, string creationDate);
};


class Node {
public:
    User* user;
    Node* left;
    Node* right;
    int height;

    Node(User* user);
};

class AVLTree {
public:
    Node* root;

    AVLTree(); // Constructor del árbol AVL

    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* node, User* user);
    User* search(Node* node, int id);
    void inorder(Node* node);
};




#endif //USERAVL_H


#endif // BINARY_SEARCH_H


