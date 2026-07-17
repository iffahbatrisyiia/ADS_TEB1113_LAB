#include <iostream>

using namespace std;

void bubbleSort(int A[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                //Swap elements
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
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

    bubbleSort(A, n);

    cout << "Sorted Array: ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }

    return 0;
}