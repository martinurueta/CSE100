#include <iostream>

using namespace std;
void Maxheap (int A[], int i, int n){
    int largest = i; // we state the largest as the root
    int l = 2 * i + 1; //we look at the left childof the root
    int r = 2 * i + 2; // right child of the root
    if (l < n && A[l] > A[largest]){
        largest = l; // if left child is larger than root, we make left child largest
    }
    if (r < n && A[r] > A[largest]){
        largest = r; // if right child is larger than root, we make right child largest
    }
    if (largest != i){// if the largest is not equal to the root
        swap(A[i], A[largest]);// swap a[i] with largest
        
        Maxheap (A, largest, n);// we recursively heapify the affected sub-tree
    }
}
void HeapSort(int A[], int n){

    for (int i = n / 2 - 1; i >= 0; i--){
        Maxheap(A, i, n); // rearrage array / roots and childs
    }
    for (int i = n - 1; i >= 0; i--){// after we rearrage array from biggest to smallest
        swap(A[0], A[i]);// we swap root to the end
        Maxheap(A, 0, i);// we then find the next biggest
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