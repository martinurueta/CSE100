#include <iostream>

using namespace std;
int partition (int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int g = p; g <= r - 1; g++){
        if (A[g] <= x){
            i++;
            swap(A[i], A[g]);
        }
    }
    swap(A[i+1], A[r]);
    return (i + 1);
}

void quickSort(int A[], int p, int r){
    if (p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main(){
    int arraySize, userInput;
    cin >> arraySize;
    int array[arraySize];
    
    for(int i = 0; i < arraySize; i++){
        cin >> userInput;
        array[i] = userInput;
    }

    quickSort(array, 0, arraySize-1);
    for(int i = 0; i < arraySize; i++){
        cout << array[i] <<";";
    }
}