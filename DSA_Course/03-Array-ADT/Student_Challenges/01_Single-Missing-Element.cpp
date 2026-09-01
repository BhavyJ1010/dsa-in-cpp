#include <iostream>
using namespace std;

int Single_Missing_Element(int arr[], int sz){
    int diff = arr[0] - 0;
    int miss;

    for(int i=0; i<sz; i++){
        if((arr[i]-i) != diff){
            miss = diff+i;
            break;
        }
    }

    return miss;
}

int main(){
    int n = 7;
    int arr[n] = {3,4,5,6,7,9,10}; //sorted array

    cout<<Single_Missing_Element(arr, n);

    return 0;
}