#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack(): topNode(nullptr) {}

    void push(int value);   // Declaración
    void pop();             // Declaración
    int top();              // Declaración
    bool isEmpty();         // Declaración
};

#endif
