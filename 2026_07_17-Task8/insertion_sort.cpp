#include <iostream>

using namespace std;

void insertionSort(int A[], int n){
    for(int i=1;i<n;i++){
        int key = A[i];
        int j = i-1;

        //Move elements greater than key one position ahead
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        } 
        //Insert the key into its correct position
        A[j+1] = key;
    }
}

int main(){
    int A[] = {5, 2, 9, 1, 7};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Unsorted Array: ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << "\n";

    insertionSort(A, n);

    cout << "Sorted Array: ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }

    return 0;
}