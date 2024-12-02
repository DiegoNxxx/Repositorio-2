#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "El Stack está vacío." << endl;
        return;
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

int Stack::top() {
    if (isEmpty()) {
        cout << "El Stack está vacío." << endl;
        return -1;
    }
    return topNode->data;
}

bool Stack::isEmpty() {
    return topNode == nullptr;
}
