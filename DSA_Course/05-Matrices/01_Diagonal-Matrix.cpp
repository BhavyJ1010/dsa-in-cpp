#include<iostream>
using namespace std;

struct Matrix{
    int* A;
    int n;
};

void set(Matrix* m, int val, int i, int j){
    if(i==j){
        m->A[i-1]=val;
    }
}

int get(Matrix m, int i, int j){
    if(i==j){
        return m.A[i-1];
    }

    return 0;
}

void display(Matrix m){

    cout<<endl;

    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){

            if(i==j){
                cout<<m.A[i-1]<<"\t";
            }
            else{
                cout<<0<<"\t";
            }
        }

        cout<<endl;
    }
}

int main(){

    Matrix m;

    cout<<"Enter dimension of diagonal matrix: ";
    cin>>m.n;

    m.A=new int[m.n];

    int val;

    cout<<"Enter diagonal elements: "<<endl;

    for(int i=1; i<=m.n; i++){
        cin>>val;
        set(&m,val,i,i);
    }

    cout<<endl<<"Diagonal Matrix:"<<endl;
    display(m);

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Value at ("<<i<<","<<j<<") is: "<<get(m,i,j)<<endl;

    delete[] m.A;

    return 0;
}