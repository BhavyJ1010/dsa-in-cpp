#include <iostream>
using namespace std;

void Missing_Element(int arr[], int max, int min, int sz){
    int* H = new int[max+1]{}; //Hash Table initialized to all zeros.

    for(int i=0; i<sz; i++){
        H[arr[i]] = 1;
    }

    for(int i=min; i<=max; i++){
        if(H[i] == 0){
            cout<<i<<"\t";
        }
    }

    delete[] H;
}

int main(){
    int size = 9;
    int arr[size] = {8,5,20,9,19,2,7,3,16}; //unsorted array

    int max = 20, min = 2;

    Missing_Element(arr, max, min, size);

    return 0;
}