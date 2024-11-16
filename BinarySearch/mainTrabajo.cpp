#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> vec, int target){
    for (int numero : vec) {
        if (numero > target) {
            return numero;
        }
    }
    return -1; 
}

int main(){

vector<int> vec = {5,2,9,7,4,6};
int target =5;

int index = binarySearch(vec, target);

if(index != -1){
    cout << "elemento encontrado en el indice:" << index;
} else {
    cout << "elemento no encontrado";
}

return 0;
}
