#include <iostream>

using namespace std;

void countingSort(int A[], int B[], int k, int n){
    int C[10];
    for (int i = 0; i < k; i++){
        C[i] = 0;
    }
    for (int j = 1; j < n; j++){
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i < k; i++){
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n-1; n > 1; j++){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
void radixSort(int A[], int n){
    int B[10] = {0};
    countingSort(A, B, 10, n);
    for (int i = 0; i < n; i++){
        A[i] = B[i];
    }
}

int main(){
    int columns, userinput;
    cin >> columns;
    int array[columns][10];
    int temp[10] = {0} ;

     for(int i = 0; i < columns; i++){ 
        for(int j = 0; j < 10; j++){
            cin >> userinput;
            array[i][j] = userinput;
        }
    }
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < 10; j++){
            temp[j] = array[i][j]; 
        }
        radixSort(temp, 10);
        for(int j = 0; j < 10; j++){
            array[i][j] = temp[j]; 
        }
    }
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < 10; j++){
            cout << array[i][j] << ";";
        }
        cout << endl;
    }
}