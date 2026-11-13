
#include <iostream>
using namespace std;

// Counting Sort for non-negative integers.
void CountingSort(int A[], int n){

    if(n <= 1){
        return;
    }

    int max = A[0];

    for(int i=1; i<n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    int *count = new int[max+1];

    for(int i=0; i<=max; i++){
        count[i] = 0;
    }

    // Count frequency of each element.
    for(int i=0; i<n; i++){
        count[A[i]]++;
    }

    // Reconstruct the sorted array.
    int j = 0;

    for(int i=0; i<=max; i++){
        while(count[i] > 0){
            A[j] = i;
            j++;
            count[i]--;
        }
    }

    delete[] count;
}

void Display(int A[], int n){

    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }

    cout << endl;
}

int main(){

    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    CountingSort(A, n);

    cout << "Sorted Array:   ";
    Display(A, n);

    return 0;
}
