#include <iostream>

using namespace std;
void merge(int array[], int begin, int mid, int end){
    int leftArrayNum = mid - begin + 1;
    int rightArrayNum = end - mid;
    int L[leftArrayNum];
    int R[rightArrayNum];
    for(int i = 0; i < leftArrayNum; i++){
        L[i] = array[begin+i];
    }
    for(int i = 0; i < rightArrayNum; i++){
        R[i] = array[mid + i + 1];
    }
    int leftIndex = 0;
    int rightIndex = 0;
    int k = begin;
    while(leftIndex < leftArrayNum && rightIndex < rightArrayNum){
        if (L[leftIndex] <= R[rightIndex]){
            array[k] = L[leftIndex];
            leftIndex++;
        }else{
            array[k] = R[rightIndex];
            rightIndex++;
        }
        k++;
    }
    while (leftIndex < leftArrayNum){
        array[k] = L[leftIndex];
        leftIndex++;
        k++;
    }
    while (rightIndex < rightArrayNum){
        array[k] = R[rightIndex];
        rightIndex++;
        k++;
    }

}
void mergeSort(int array[], int begin, int end){
    if (begin < end){
        int mid = (begin + end) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, (mid + 1), end);
        merge(array, begin, mid, end);
    }else{
        return;
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

    mergeSort(array, 0, arraySize-1);
    for(int i = 0; i < arraySize; i++){
        cout << array[i] <<";";
    }



}