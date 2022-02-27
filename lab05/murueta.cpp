#include <iostream>
#include <deque>
using namespace std;

void countingSort(deque<int> A[], deque<int> B[], int k, int n){
    int C[10];
    
    for(int i = 0; i < 10; i++){ // initializes the array C to all zeros
        C[i] = 0;  
    }
    for(int j = 0; j < n; j++){ // inspects each input element. If the value of an input element is i, we increment C[i]
        C[A[j][k]]=C[A[j][k]]+1; // C[i] holds the number of input elements equal to i for each integer i = 0, 1,...,k.
    }
    for(int i = 1; i < 10; i++){ 
        C[i] = C[i] + C[i-1]; // determine for each i, how many input elements are less than or equal to i by keeping a running sum of the array C
    }
    for(int j = n-1; j >= 0; j--){ // places each element A[j] into its correct sorted position in the output array B
        B[C[A[j][k]]-1] = A[j];
        C[A[j][k]] = C[A[j][k]] - 1;
    }
}

void radixSort(deque<int> A[], deque<int> B[], int n){
    for(int i = 9; i >= 0; i--){
        countingSort(A, B, i, n);
        for(int i = 0; i < n; i++){ // sets A to B.
            A[i] = B[i];
        }
    }
}

int main(){
    int columns, userinput; // gets size of array from user
    cin >> columns;
    deque<int>A[columns];
    deque<int>B[columns];
    
    for(int i = 0; i < columns; i++){ 
        for(int j = 0; j < 10; j++){
            cin >> userinput;
            A[i].push_back(userinput);
        }
    }
    radixSort(A, B, columns);

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < 10; j++){
            cout << B[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
    
}