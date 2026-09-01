#include <iostream>
using namespace std;

void duplicates(int arr[], int sz){
    int last_duplicate = -1;

    for(int i=0; i<sz-1; i++){
        int j = i+1;

        if(arr[i] == arr[i+1] && last_duplicate != arr[i]){
            last_duplicate = arr[i];

            while(j<sz && arr[j] == last_duplicate){
                j++;
            }

            cout<<arr[i]<<" appears "<<j-i<<" times"<<endl;

            i = j-1;
        }
    }
}

int main(){
    int size = 14;
    int arr[size] = {0,0,2,5,6,6,12,13,13,13,14,14,14,14};

    duplicates(arr, size);

    return 0;
}