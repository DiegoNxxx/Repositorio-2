#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int value); // Constructor
};

class BinaryTree {
public:
    Node* root;

    BinaryTree();               // Constructor
    Node* insert(Node* node, int value); // Método para insertar
    Node* search(Node* node, int value); // Método para buscar
    void preOrder(Node* node); // Método para recorrido en preorden
    void inOrder(Node* node);  // Método para recorrido en inorden
    void postOrder(Node* node); // Método para recorrido en postorden
};

#endif
