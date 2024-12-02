class Node {
public:
    int data;     // Los datos que contiene el nodo
    Node* next;   // Puntero al siguiente nodo

    Node(int value) : data(value), next(nullptr) {}  // Constructor para inicializar
};
