#include "Queue.h"

#include <iostream>
using namespace std;

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
