#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    
    // Ejemplo de búsqueda
    int valueToSearch = 30;
    Node *result = tree.search(tree.root, valueToSearch);
    if (result) {
        cout << "Found: " << result->data << endl;
    } else {
        cout << "Not Found" << endl;
    }

    // Recorridos
    cout << "PreOrder: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "InOrder: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "PostOrder: ";
    tree.postOrder(tree.root);
    cout << endl;

    return 0;
}
