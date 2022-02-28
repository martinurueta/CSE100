#include <iostream>

using namespace std;

int partition (int A[], int p, int r){
    int x = A[r]; //pivot the end index
    int i = p - 1; // index of the smaller element 
    for (int g = p; g <= r - 1; g++){
        if (A[g] <= x){// if current element is smaller than pivot
            i++;// increment index of smaller element
            swap(A[i], A[g]); // we swap smaller with current index
        }
    }
    swap(A[i+1], A[r]); // swap right of smaller index and the end of the index
    return (i + 1); // returns the value to a new pivot that splits in half the array
}

void quickSort(int A[], int p, int r){
    if (p < r){
        int q = partition(A, p, r);// q is the partition index
        quickSort(A, p, q - 1);// separately sort elements of lower half
        quickSort(A, q + 1, r);// separately sort elements of upper half
        // continues the partition until p is no longer p < r
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