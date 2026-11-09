
#include <iostream>
using namespace std;

// Restore Max Heap property for the subtree rooted at i.
// Its left and right subtrees must already be Max Heaps.
void Heapify(int A[], int n){
    // Start from the last non-leaf node and move towards the root.
    for(int i=(n/2)-1; i>=0; i--){

        int p = i;
        int j = 2*p + 1;

        // Move the current element down if it is smaller than a child.
        while(j < n){

            // Select the larger child.
            if(j+1 < n && A[j+1] > A[j]){
                j = j+1;
            }

            // Stop if the parent is already greater than the larger child.
            if(A[p] >= A[j]){
                break;
            }

            int temp = A[p];
            A[p] = A[j];
            A[j] = temp;

            p = j;
            j = 2*p + 1;
        }
    }
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
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    Heapify(A, n);

    cout << "Heapified Array: ";
    Display(A, n);

    return 0;
}
