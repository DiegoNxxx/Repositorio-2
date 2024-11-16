#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNote(Node* &head, int value){
    Node* newNode = new Node(); // crear un nuevo nodo de memoria
    newNode -> data = value; // Asignacion de value a la estructura accediendo a data
    newNode -> next = nullptr; // el siguiente nodo es nullptr

    if(head == nullptr) {
        head = newNode; // si la lista esta vacía el nuevo nodo es la head

    } else {
        Node* temp = head; // crear una variable temporal que almacene el current head
        while (temp -> next != nullptr) // recorremos la lista hasta el ultimo nodo
        {
            temp = temp -> next;
        }
        temp -> next = newNode; // enlazamos 
    }

}

void showList(Node* head){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    
}

int main(){

    Node* list = nullptr;
    addNote(list, 40);
    addNote(list, 800);
    addNote(list, 80);

    cout << "lista de valores" << endl;
    showList(list);

    return 0;
}