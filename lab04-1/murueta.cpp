#include <iostream>

using namespace std;
void Maxheap (int A[], int i, int n){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest]){
        largest = l;
    }
    if (r < n && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        swap(A[i], A[largest]);
        Maxheap (A, largest, n);
    }
}
void HeapSort(int A[], int n){

    for (int i = n / 2 - 1; i >= 0; i--){
        Maxheap(A, i, n);
    }
    for (int i = n - 1; i >= 0; i--){
        swap(A[0], A[i]);
        Maxheap(A, 0, i);
    }
}

int main () {
    int arraySize, userInput;
    cin >> arraySize;
    int array[arraySize];
    
    for(int i = 0; i < arraySize; i++){
        cin >> userInput;
        array[i] = userInput;
    }

    HeapSort(array, arraySize);
    for(int i = 0; i < arraySize; i++){
        cout << array[i] <<";";
    }

}