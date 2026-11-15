#include<iostream>
using namespace std;

void ShellSort(int A[], int n){
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int x=A[i];
            int j=i;

            while(j>=gap && A[j-gap]>x){
                A[j]=A[j-gap];
                j=j-gap;
            }

            A[j]=x;
        }
    }
}

void Display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[]={23, 12, 1, 8, 34, 54, 2, 3};
    int n=sizeof(A)/sizeof(A[0]);

    cout<<"Before Sorting: ";
    Display(A,n);

    ShellSort(A,n);

    cout<<"After Sorting: ";
    Display(A,n);

    return 0;
}