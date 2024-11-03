#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Función que verifica si dos cadenas son anagramas
bool SonAnagramas(string a, string b) {
    if (a.length() != b.length()) {
        return false; 
    }

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 

    return a == b; // Comparamos las cadenas ordenadas
}

int main() {
    vector<string> listadecosas = {"abc", "bc", "13", "231", "xz", "zyx", "456", "654"};

    // Comprobar anagramas
    for (size_t i = 0; i < listadecosas.size(); i++) {
        for (size_t j = i + 1; j < listadecosas.size(); j++) {
            if (SonAnagramas(listadecosas[i], listadecosas[j])) {
                cout << listadecosas[i] << " y " << listadecosas[j] << " son anagramas." << endl;
            }
        }
    }

    return 0;
}
