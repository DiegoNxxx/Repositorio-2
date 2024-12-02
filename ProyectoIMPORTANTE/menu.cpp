#include <iostream>
#include <vector>
#include <string>
#include "BINARYSEARCH.h"
#include "STACK.h"

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Declaración de funciones
void addNode(Node*& head, int value); 
void showList(Node* head);
void bubbleSort(vector<int>& data);
void selectionSort(vector<int>& data);
void insertionSort(vector<int>& data);
void mergeSort(vector<int>& data);
void quickSort(vector<int>& data, int low, int high);


int main() {
    vector<int> data;
    string inputText;
    int input, target, inputText, N, value, option, size;
    vector<int> data(N); 
    vector<int> array;
    Node* list = nullptr;
    Queue q(size);

    do {
        // Mostrar el menú
        cout << "Menú de opciones:" << endl;
        cout << "1. Ingresar datos" << endl;
        cout << "2. BinarySearch" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Quick Sort" << endl;
        cout << "8. Linked List" << endl;
        cout << "9. Stacks" << endl;
        cout << "10. Queue" << endl;
        cout << "11. AVL" << endl;
        cout << "12. Dijkstra" << endl;
        cout << "13. Matrices Adyac." << endl;
        cout << "14. BFS" << endl;
        cout << "15. DFS" << endl;
        cout << "16. LP" << endl;
        cout << "17. LQ" << endl;
        cout << "18. BST" << endl;
        cout << "19. Salir" << endl;

        // Leer la opción ingresada por el usuario
        cout << "Ingresa el número de la opción que deseas elegir: ";
        cin >>inputText;

        // Convertir la opción a entero para hacer la comparación
        input = stoi(inputText);

        // Ejecutar la opción seleccionada usando switch
        switch (input) {
          case 2:  // BinarySearch
                data.clear();
                cout << "Seleccionaste la opción 2: BinarySearch\n";
                cout << "¿Cuántos números quieres ingresar? ";
                cin >> N;
                for (int i = 0; i < N; ++i) {
                    int num;
                    cout << "Número " << i + 1 << ": ";
                    cin >> num;
                    data.push_back(num);
                }
                cout << "Ingresa el número objetivo: ";
                cin >> target;
                
                // Realizar la búsqueda (asegúrate de tener definida la función)
                int result = binarySearch(data, target);
                if (result != -1) {
                    cout << "Elemento encontrado en el índice: " << result << endl;
                } else {
                    cout << "Elemento no encontrado." << endl;
                }
                break;

            case 3:  // Bubble Sort
                data.clear();
                cout << "Seleccionaste la opción 3: Bubble Sort\n";
                cout << "¿Cuántos números quieres ordenar? ";
                cin >> N;
                for (int i = 0; i < N; i++) {
                    int temp;
                    cout << "Número " << i + 1 << ": ";
                    cin >> temp;
                    data.push_back(temp);
                }
                bubbleSort(data);
                cout << "Números ordenados: ";
                for (int num : data) cout << num << " ";
                cout << endl;
                break;

            case 4:
        cout << "Ingresa la cantidad de números a ordenar: ";
        cin >> N;
        for (int i = 0; i < N; i++) {
            cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
            cin >> data[i];
        }

        // Ordenar el vector usando Selection Sort
        selectionSort(data);

        // Mostrar los números ordenados
        cout << "Números ordenados: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
                
                break;

            case 5:
                cout << "Seleccionaste la opcion 5: Insertion Sort" << endl;
        cout << "Ingresa la cantidad de números a ordenar: ";
        cin >> N;
        for (int i = 0; i < N; i++) {
        int temp;
        cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
        cin >> temp;
        data.push_back(temp);
    }
        // Ordenar usando Insertion Sort
    insertionSort(data);
    
    // Eliminar números que no son primos
    eliminarNoPrimos(data);
        // Mostrar los números primos ordenados
        cout << "Números primos ordenados: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;

                break;

            case 6:
            cout << "Seleccionaste la opcion 6: Merge Sort" << endl;
            cout << "Ingresa la cantidad de números a ordenar: ";
            cin >> N;
                // Leer los números del usuario
            for (int i = 0; i < N; i++) {
                int temp;
                cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                cin >> temp;
                array.push_back(temp);
            }
                // Ordenar el arreglo usando Merge Sort
            mergeSort(array);
                // Mostrar los números ordenados
            cout << "Números ordenados: ";
            for (int num : array) {
                cout << num << " ";
            }
            cout << endl;
                break;

            case 7:
                cout << "Seleccionaste la opcion 7: Quick Sort" << endl;
            // Simulación del menú interactivo: QuickSort
                cout << "Seleccionaste la opción 7: Quick Sort" << endl;
                cout << "Ingresa la cantidad de números a ordenar: ";
                cin >> N;

                // Leer los números del usuario
                for (int i = 0; i < N; i++) {
                    int temp;
                    cout << "Ingresa un número (" << i + 1 << "/" << N << "): ";
                    cin >> temp;
                    array.push_back(temp);
                }

                // Aplicar QuickSort al arreglo
                quickSort(array, 0, N - 1);

                // Mostrar los números ordenados
                cout << "Números ordenados: ";
                for (int num : array) {
                    cout << num << " ";
                }
                cout << endl;
                            
                break;

            case 8:
                cout << "Seleccionaste la opcion 8: Linked List" << endl;
                cout << "Ingresa la cantidad de valores a agregar en la lista: ";
                cin >> N;

                for (int i = 0; i < N; i++) {
                    cout << "Ingresa el valor " << i + 1 << ": ";
                    cin >> value;
                    addNode(list, value);
                }

                // Mostrar la lista completa
                cout << "Lista de valores: ";
                showList(list);
                break;

            case 9:
                cout << "Seleccionaste la opcion 9: Stacks" << endl;
                Stack stack;
                stack.push(30);
                stack.push(50);
                stack.push(70);

                cout << "El elemento top es: " << stack.top() << endl;
                stack.pop();
                cout << "Después del pop, el elemento top es: " << stack.top() << endl;

                break;
                

            case 10:
               do {
                    cout << "\nOperaciones de Queue:\n";
                    cout << "1. Enqueue\n2. Dequeue\n3. Mostrar frente\n4. Salir\n";
                    cout << "Opción: ";
                    cin >> option;
                    switch (option) {
                        case 1:
                            cout << "Ingresa el valor a agregar: ";
                            cin >> value;
                            q.enqueue(value);
                            break;
                        case 2:
                            q.dequeue();
                            break;
                        case 3:
                            cout << "Elemento al frente: " << q.frontElement() << endl;
                            break;
                        default:
                            cout << "Opción inválida.\n";
                    }
                } while (option != 4);
                break;
            case 11:
                cout << "Seleccionaste la opcion 11: AVL" << endl;
                break;

            case 12:
                cout << "Seleccionaste la opcion 12: Dijkstra" << endl;
                break;

            case 13:
                cout << "Seleccionaste la opcion 13: Matrices Adyac." << endl;
                break;

            case 14:
                cout << "Seleccionaste la opcion 14: BFS" << endl;
                break;

            case 15:
                cout << "Seleccionaste la opcion 15: DFS" << endl;
                break;

            case 16:
                cout << "Seleccionaste la opcion 16: LP" << endl;
                break;

            case 17:
                cout << "Seleccionaste la opcion 17: LQ" << endl;
                break;

            case 18:
                cout << "Seleccionaste la opcion 18: BST" << endl;
                break;

            case 19:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, ingresa un número entre 1 y 19." << endl;
        }

        cout << endl; // Separador para mejor visualización
    } while (input != 19);

    return 0;
}
