#include <iostream>

using namespace std;

//Merge two sorted parts
void merge(int A[], int left, int mid, int right) {
    int temp[100];          //Temporary array (works if array size <= 100)

    int i = left;           //Left half
    int j = mid + 1;        //Right half
    int k = left;           //Temp array index

    while (i <= mid && j <= right) {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= mid)
        temp[k++] = A[i++];

    while (j <= right)
        temp[k++] = A[j++];

    //Copy back to original array
    for (int x = left; x <= right; x++)
        A[x] = temp[x];
}

//Merge Sort
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(A, left, mid);      // Left half
        mergeSort(A, mid + 1, right); // Right half
        merge(A, left, mid, right);   // Merge both halves
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

    mergeSort(A, 0, n-1);

    cout << "Sorted Array: ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }

    return 0;
}