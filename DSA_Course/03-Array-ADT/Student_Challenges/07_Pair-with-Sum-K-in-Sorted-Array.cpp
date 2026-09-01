#include <iostream>
using namespace std;

void sum_pair(int arr[], int sz, int sum){
    for(int i=0, j=sz-1; i<j;){
        if(arr[i]+arr[j] == sum){
            cout<<arr[i]<<"+"<<arr[j]<<"="<<sum<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] < sum){
            i++;
        }
        else{
            j--;
        }
    }
}

int main(){
    int size = 9;
    int arr[size] = {0,1,4,5,6,9,10,13,19}; //sorted array

    sum_pair(arr, size, 10);

    return 0;
}