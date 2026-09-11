#include<iostream>
using namespace std;

class TriDiagonal{
    private:
        int n;
        int* A;

    public:
        TriDiagonal(int n){
            this->n=n;
            A=new int[3*n-2];
        }

        ~TriDiagonal(){
            delete[] A;
        }

        void set(int val,int i,int j){

            if(i-j==1){
                A[i-2]=val;
            }
            else if(i==j){
                A[n-1+i-1]=val;
            }
            else if(j-i==1){
                A[2*n-1+i-1]=val;
            }
        }

        int get(int i,int j){

            if(i-j==1){
                return A[i-2];
            }
            else if(i==j){
                return A[n-1+i-1];
            }
            else if(j-i==1){
                return A[2*n-1+i-1];
            }

            return 0;
        }

        void display(){

            cout<<endl;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<get(i,j)<<"\t";
                }
                cout<<endl;
            }
        }
};

int main(){

    int n;

    cout<<"Enter dimension of tri-diagonal matrix: ";
    cin>>n;

    TriDiagonal T(n);

    int val;

    cout<<"Enter tri-diagonal elements:"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            if(abs(i-j)<=1){
                cin>>val;
                T.set(val,i,j);
            }
        }
    }

    cout<<endl<<"Tri-Diagonal Matrix:";
    T.display();

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Value at ("<<i<<","<<j<<") is: "
        <<T.get(i,j)<<endl;

    return 0;
}