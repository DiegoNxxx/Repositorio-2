#ifndef stack.hpp
#define stack.hpp

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;
public:
    Stack(): topNode(nullptr){}
    
    void push(int value){
        Node* newNode = new Node();
        newNode -> data = value;
        newNode -> next = topNode;
        topNode = newNode;
    }

    void pop() {
        if(isEmpty()) {
            cout << "El stack está vacío" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode-> next;
        delete temp;
    }

    int top(){
        if(isEmpty()) {
            cout << "El stack  esta vacío";
            return 0;
        }
        return topNode -> data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

#endif