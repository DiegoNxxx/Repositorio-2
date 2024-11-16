#include <iostream>
#include <vector>
using namespace std;

bool NumeroPrimo(int num) { // bool para que sean valores de verdadero y falso 
    for (int i = 2; i < num; ++i) { 
        if (num % i == 0) return false; // Si es divisible por i, no es primo
    }
        if (num ==2) return false;
        
    return true; 
}

void eliminarNoPrimos(vector<int>& numeros) {
    vector<int> primos;

    for (int num : numeros) {
        if (NumeroPrimo(num)) {
            primos.push_back(num); // regresa los primos nomas
        }
    }
    numeros = primos;
}



void insertionSort(vector<int>& arr){
    int n = arr.size();


    for (int i =1; i < n; i++){
        int key = arr[i];
        int j= i-1;

        while (j >= 0 && arr[j]> key)
        {
            arr[j+1]= arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    
}



int main(){
    vector<int> arr= {12,5,3,7,11,13,10,7,1,8,4,2};

    insertionSort(arr) ;
    eliminarNoPrimos(arr);

    for(int num:arr){
        cout << num << ",";
    }

    return 0;


}