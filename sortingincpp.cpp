//
// Created by maldo on 11/27/2025.
//

#include <iostream>
#include <ctime>

void swap(int *x, int *y);
void selectionSort(int array[], int size);
void printArray(int array[], int size);
void insertionSort(int array[], int size);
void quickSortWrapper(int array[], int size);
int partition(int array[], int start, int end);
void quicksortRecursion(int array[], int start, int end);
void mergeSort(int array[], int size);
void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int array[]);

int main (){
    srand(time(NULL));
    int array[] = {7,8,6,2,5,3,4,1,3254, 567,53,454,65456, 654,754,754,745,74,5754,7455};
    int size = sizeof(array)/sizeof(array[0]);

    printArray(array, size);
    mergeSort(array, size);
    printArray(array, size);


}

void selectionSort(int array[], int size){
    //finds minimum value in array and repeatedly sorts
    int minIndex = 0;

    for (int i = 0; i < size - 1; i++){
        minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(&array[i], &array[minIndex]);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int array[], int size) {
    //insertion sort; repeatedly inserts elements left to right, in correct order by shifting

    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void swap (int *x, int *y){
int temp = *x;
*x = *y;
*y = temp;
}

void quickSortWrapper(int array[], int size){
    quicksortRecursion(array, 0, size-1);
}

void quicksortRecursion(int array[], int start, int end){
    if (start < end) {
        int pivotIndex = partition(array, start, end);

        quicksortRecursion(array, start, pivotIndex - 1);
        quicksortRecursion(array, pivotIndex + 1, end);
    }
}

int partition(int array[], int start, int end){

    int pivotIndex = start + (rand() % (end - start + 1));

    if (pivotIndex != end){
        swap(&array[pivotIndex],&array[end]);
    }
    int pivotValue = array[end];

    int i = start;

    for (int j = start; j < end; j++){
        if (array[j] <= pivotValue){
            swap(&array[i],&array[j]);
            i++;
        }
    }
    swap(&array[i],&array[end]);

    return i;
}

void mergeSort(int array[], int size){
    if (size <= 1) return; //base case

    int middle = size / 2;

    int *leftArray = new int[middle];
    int *rightArray = new int[size - middle];

    int i = 0; //left array
    int j = 0; //right array

    for (i = 0; i < size; i++){
        if (i < middle){
            leftArray[i] = array[i];
        }
        else {
            rightArray[j] = array[i];
            j++;
        }
    }
    mergeSort(leftArray, middle);
    mergeSort(rightArray, size - middle);
    merge(leftArray, middle, rightArray, size - middle, array);

    delete[] leftArray;
    delete[] rightArray;
}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int array[]){

    int i = 0, l = 0, r = 0; //indices

    //check conditions for merging
    while (l < leftSize && r < rightSize){
        if (leftArray[l] <= rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else{
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
    while (l < leftSize){
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize){
        array[i] = rightArray[r];
        i++;
        r++;
    }
}