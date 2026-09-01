#include <iostream>
using namespace std;

void pair_sum(int arr[], int sz, int sum){
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            if(arr[i]+arr[j] == sum){
                cout<<arr[i]<<"+"<<arr[j]<<"="<<sum<<endl;
            }
        }
    }
}

void pair_sum_hashing(int arr[], int max, int sz, int sum){
    int* H = new int[max+1]{};

    for(int i=0; i<sz; i++){
        if(sum-arr[i] >= 0 && sum-arr[i] <= max && H[sum-arr[i]] == 1){
            cout<<arr[i]<<"+"<<sum-arr[i]<<"="<<sum<<endl;
        }

        if(arr[i] >= 0 && arr[i] <= max){
            H[arr[i]] = 1;
        }
    }

    delete[] H;
}

int main(){
    int size = 9, max = 19;
    int arr[size] = {6,10,4,1,9,13,5,19,0};

    pair_sum(arr, size, 10);

    cout<<endl;

    pair_sum_hashing(arr, max, size, 10);

    return 0;
}