#include <iostream>
using namespace std;

int main()

{
    int capacity = 5;
    int* number = new int[capacity];
    int entries = 0;

    while (true)
    {
        cout << "Numbers: ";
        cin >> number[entries];

        if(cin.fail()) break;
        entries++;

        if (entries == capacity)
        {
            // crear una variable temporal para incrementar la memoria asignada 
            capacity *=2;
            int* temp = new int[capacity];

            // copiar los elementos de temp al arreglo de number
            for ( int i = 0; i < entries; i++)
            {
                temp[i] = number[i];
            }
            delete[] number;
            number = temp;
            
        }


        

        if (entries > capacity)
        {
            cout << "Warning: Exceeded capacity!";
            break;
        };
        
    }

     for(int i =0; i < entries; i++){
       cout << number[i] << endl;
    }
    

    return 0;
}