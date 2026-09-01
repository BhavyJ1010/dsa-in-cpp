#include <iostream>
using namespace std;

void Multiple_Missing_Element(int arr[], int sz){
    int diff = arr[0] - 0;

    for(int i=0; i<sz; i++){
        if((arr[i]-i) != diff){
            while(diff < (arr[i]-i)){
                cout<<diff+i<<"\t";
                diff++;
            }
        }
    }
}

int main(){
    int size = 4;
    int arr[size] = {3,7,9,19}; //sorted array

    Multiple_Missing_Element(arr, size);

    return 0;
}