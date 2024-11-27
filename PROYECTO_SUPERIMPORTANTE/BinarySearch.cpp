#include <iostream>
#include <vector>
#include "BinarySearch.h"
using namespace std;

// Función binarySearch
int binarySearch(vector<int> vec, int target){

    int lo =0;
    int hi = vec.size()-1;

        while (lo <= target) {
        int mid = lo + (hi-lo)/2;
        //caso base

        if(vec[mid]==target){
            return mid;
        }

        if(vec[mid] < target){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
            
        }
            return -1;

    }

// Bubblesort

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
    