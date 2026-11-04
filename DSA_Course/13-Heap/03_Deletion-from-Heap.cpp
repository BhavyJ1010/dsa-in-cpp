
#include <iostream>
using namespace std;

// Delete the maximum element (root) from a Max Heap.
// n is passed by reference because the heap loses one element.
int Delete(int A[], int& n){
    if(n == 0){
        cout << "Heap is empty. Cannot delete.\n";
        return -1;
    }

    int x = A[0];              // Maximum element
    A[0] = A[n-1];             // Move last element to the root
    n--;                       // Reduce heap size

    int i = 0;
    int j = 2*i + 1;           // Left child

    // Move the new root downward until the Max Heap property is restored.
    while(j < n){
        // Select the larger child.
        if(j+1 < n && A[j+1] > A[j]){
            j = j+1;
        }

        // Stop if parent is already greater than or equal to the larger child.
        if(A[i] >= A[j]){
            break;
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        i = j;
        j = 2*i + 1;
    }

    return x;
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
    int A[] = {40, 30, 35, 10, 15, 20, 25};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Max Heap: ";
    Display(A, n);

    int deleted = Delete(A, n);
    cout << "Deleted element: " << deleted << endl;

    cout << "Heap after deletion: ";
    Display(A, n);

    return 0;
}
