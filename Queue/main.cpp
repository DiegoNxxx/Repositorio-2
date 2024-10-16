#include <iostream>
using namespace std;

#include "Queue.h"

int main(){

    
    Queue q(5);
    q.enqueue(12);
    q.enqueue(230);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();

    cout<<"El front element es: "<< q.frontElement()<<endl;
    

    return 0;
}