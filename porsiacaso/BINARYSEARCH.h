#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

// Declaración de la función binarySearch
int binarySearch(vector<int> vec, int target);

void bubbleSort(vector<int> &vec);

void selectionSort(vector<int> &vec);

void insertionSort(vector<int>& arr);

void eliminarNoPrimos(vector<int>& numeros);

void mySwap(int& a, int& b);

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array);

void mergeSort(vector<int>& array);

int partition(vector<int>& arr, int low, int high);

void quickSort(vector<int>& arr, int low, int high);

vector<int> dijkstra(int n, int origen, int destino, const vector<vector<pair<int, int>>>& grafo);

#endif // BINARY_SEARCH_H