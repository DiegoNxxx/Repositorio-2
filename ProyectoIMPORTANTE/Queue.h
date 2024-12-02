#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int *queue;
    int front, rear, size;

public:
    Queue(int capacity);        // Constructor
    bool isEmpty();             // Verifica si la cola está vacía
    bool isFull();              // Verifica si la cola está llena
    void enqueue(int value);    // Inserta un elemento
    void dequeue();             // Elimina el primer elemento
    int frontElement();         // Devuelve el elemento del frente
    ~Queue();                   // Destructor
};

#endif
