#include <iostream>
using namespace std;

void duplicates_hashing(int arr[], int max, int sz){
    int* H = new int[max+1]{};

    for(int i=0; i<sz; i++){
        H[arr[i]]++;
    }

    for(int i=0; i<=max; i++){
        if(H[i] > 1){
            cout<<i<<" appears "<<H[i]<<" times"<<endl;
        }
    }

    delete[] H;
}

int main(){
    int size = 14;
    int max = 14;

    int arr[size] = {0,0,2,5,6,6,12,13,13,13,14,14,14,14};

    duplicates_hashing(arr, max, size);

    return 0;
}