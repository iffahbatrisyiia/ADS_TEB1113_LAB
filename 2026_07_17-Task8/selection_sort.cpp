#include <iostream>

using namespace std;

void selectionSort(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;

        // Find the index of the smallest element
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[minIndex]){
                minIndex = j;
            }
        }

        // Swap the smallest element with the first unsorted element
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
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

    selectionSort(A, n);

    cout << "Sorted Array: ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }

    return 0;
}