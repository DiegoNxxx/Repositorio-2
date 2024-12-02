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

#endif // QUEUE_H
