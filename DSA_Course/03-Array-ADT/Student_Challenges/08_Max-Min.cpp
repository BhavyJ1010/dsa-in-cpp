#include <iostream>
using namespace std;

void maxmin(int arr[], int sz){
    int max, min;
    max = min = arr[0];

    for(int i=1; i<sz; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        else if(arr[i] < min){
            min = arr[i];
        }
    }

    cout<<"maximum element = "<<max<<"\n"
        <<"minimum element = "<<min<<endl;
}

int main(){
    int size = 9;
    int arr[size] = {100,6,12,35,7,8,54,1,34};

    maxmin(arr, size);

    return 0;
}