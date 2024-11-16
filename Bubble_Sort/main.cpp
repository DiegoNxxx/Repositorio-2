#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vec) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(vec[j] > vec[j+1]) {
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

int main() {
    int N = 7;  // Define el número de calificaciones esperado

    cout << "Ingrese " << N << " calificaciones:" << endl;

    vector<int> calificaciones(N);  // Vector de tamaño N

    for (int i = 0; i < N; i++) {

        cout << "Ingresa una calificación (" << i+1 << "/" << N << "): ";
        cin >> calificaciones[i];  // Guardar la calificación en el vector
        if(calificaciones[i]>100){
            cout << "La calificacion es de más de 100\n ingrese un número menor que 100\n";

            i--;
        }
    }

    bubbleSort(calificaciones);  // Ordenar el vector calificaciones usando Bubble Sort

    cout << "Calificaciones ordenadas: ";
    for(int num : calificaciones) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
