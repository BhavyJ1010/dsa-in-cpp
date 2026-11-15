
#include <iostream>
using namespace std;

// Finds the maximum element.
int GetMax(int A[], int n){

    int max = A[0];

    for(int i=1; i<n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
}

// Stable Counting Sort based on a particular digit.
void CountSort(int A[], int n, int exp){

    int *output = new int[n];
    int count[10] = {0};

    // Count occurrences of each digit.
    for(int i=0; i<n; i++){
        int digit = (A[i]/exp)%10;
        count[digit]++;
    }

    // Convert frequencies into cumulative positions.
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    // Build output array from right to left to maintain stability.
    for(int i=n-1; i>=0; i--){

        int digit = (A[i]/exp)%10;

        output[count[digit]-1] = A[i];
        count[digit]--;
    }

    // Copy output back into original array.
    for(int i=0; i<n; i++){
        A[i] = output[i];
    }

    delete[] output;
}

// LSD Radix Sort.
void RadixSort(int A[], int n){

    if(n <= 1){
        return;
    }

    int max = GetMax(A, n);

    // Sort according to each digit position.
    for(int exp=1; max/exp>0; exp*=10){
        CountSort(A, n, exp);
    }
}

void Display(int A[], int n){

    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }

    cout << endl;
}

int main(){

    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    RadixSort(A, n);

    cout << "Sorted Array:   ";
    Display(A, n);

    return 0;
}

