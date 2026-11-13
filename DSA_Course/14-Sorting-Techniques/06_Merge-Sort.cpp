
#include <iostream>
using namespace std;

// Merges two sorted portions:
// A[low...mid] and A[mid+1...high]
void Merge(int A[], int temp[], int low, int mid, int high){

    int i = low;
    int j = mid+1;
    int k = low;

    // Compare elements from both portions.
    while(i <= mid && j <= high){

        if(A[i] <= A[j]){
            temp[k] = A[i];
            i++;
        }
        else{
            temp[k] = A[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from the left portion.
    while(i <= mid){
        temp[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right portion.
    while(j <= high){
        temp[k] = A[j];
        j++;
        k++;
    }

    // Copy merged elements back into the original array.
    for(int x=low; x<=high; x++){
        A[x] = temp[x];
    }
}


// Recursive Merge Sort
void MergeSortRecursive(int A[], int temp[], int low, int high){

    if(low < high){

        int mid = low + (high-low)/2;

        // Divide into two halves.
        MergeSortRecursive(A, temp, low, mid);
        MergeSortRecursive(A, temp, mid+1, high);

        // Merge the two sorted halves.
        Merge(A, temp, low, mid, high);
    }
}


// Iterative Merge Sort
void MergeSortIterative(int A[], int n){

    int *temp = new int[n];

    // Current size of the portions being merged.
    for(int width=1; width<n; width*=2){

        // Merge adjacent portions of size width.
        for(int low=0; low<n-width; low += 2*width){

            int mid = low + width - 1;
            int high = low + 2*width - 1;

            if(high >= n){
                high = n-1;
            }

            Merge(A, temp, low, mid, high);
        }
    }

    delete[] temp;
}


void Display(int A[], int n){

    cout << "[";

    for(int i=0; i<n; i++){
        cout << A[i];

        if(i < n-1){
            cout << ", ";
        }
    }

    cout << "]" << endl;
}


int main(){

    int A[] = {40, 20, 60, 10, 30, 50};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    int *temp = new int[n];

    MergeSortRecursive(A, temp, 0, n-1);

    delete[] temp;

    cout << "Recursive Merge Sort: ";
    Display(A, n);


    int B[] = {40, 20, 60, 10, 30, 50};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "\nOriginal Array: ";
    Display(B, m);

    MergeSortIterative(B, m);

    cout << "Iterative Merge Sort: ";
    Display(B, m);


    int C[] = {50, 40, 30, 20, 10};
    int k = sizeof(C)/sizeof(C[0]);

    cout << "\nReverse Sorted Array: ";
    Display(C, k);

    MergeSortIterative(C, k);

    cout << "After Merge Sort: ";
    Display(C, k);


    int D[] = {30, 10, 30, 20, 10};
    int l = sizeof(D)/sizeof(D[0]);

    cout << "\nArray with Duplicates: ";
    Display(D, l);

    int *temp2 = new int[l];

    MergeSortRecursive(D, temp2, 0, l-1);

    delete[] temp2;

    cout << "After Merge Sort: ";
    Display(D, l);
}
