#include<iostream>
using namespace std;

class UpperTriangular{
    private:
        int n;
        int* A;
        int* B;

    public:
        UpperTriangular(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
            B=new int[n*(n+1)/2];
        }

        ~UpperTriangular(){
            delete[] A;
            delete[] B;
        }

        void set_row_major(int val,int i,int j){
            if(j>=i){
                A[(i-1)*(2*n-i+2)/2+j-i]=val;
            }
        }

        int get_row_major(int i,int j){
            if(j>=i){
                return A[(i-1)*(2*n-i+2)/2+j-i];
            }
            return 0;
        }

        void set_column_major(int val,int i,int j){
            if(j>=i){
                B[j*(j-1)/2+i-1]=val;
            }
        }

        int get_column_major(int i,int j){
            if(j>=i){
                return B[j*(j-1)/2+i-1];
            }
            return 0;
        }

        void display_row_major(){
            cout<<endl;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<get_row_major(i,j)<<"\t";
                }
                cout<<endl;
            }
        }

        void display_column_major(){
            cout<<endl;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<get_column_major(i,j)<<"\t";
                }
                cout<<endl;
            }
        }
};

int main(){

    int n;

    cout<<"Enter dimension of upper triangular matrix: ";
    cin>>n;

    UpperTriangular U(n);

    int val;

    cout<<"Enter upper triangular elements:"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            cin>>val;

            U.set_row_major(val,i,j);
            U.set_column_major(val,i,j);
        }
    }

    cout<<endl<<"Upper Triangular Matrix (Row-Major Storage):";
    U.display_row_major();

    cout<<endl<<"Upper Triangular Matrix (Column-Major Storage):";
    U.display_column_major();

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Row-major value at ("<<i<<","<<j<<") is: "
        <<U.get_row_major(i,j)<<endl;

    cout<<"Column-major value at ("<<i<<","<<j<<") is: "
        <<U.get_column_major(i,j)<<endl;

    return 0;
}