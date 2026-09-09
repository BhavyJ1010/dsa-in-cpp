#include<iostream>
using namespace std;

class LowerTriangular{

    private:
        int n;
        int* A;
        int* B;

    public:

        LowerTriangular(int n){
            this->n=n;

            // Row-major storage
            A=new int[n*(n+1)/2];

            // Column-major storage
            B=new int[n*(n+1)/2];
        }

        ~LowerTriangular(){
            delete[] A;
            delete[] B;
        }

        // Row-major mapping
        void set_row_major(int val,int i,int j){
            if(i>=j){
                A[i*(i-1)/2+j-1]=val;
            }
        }

        int get_row_major(int i,int j){
            if(i>=j){
                return A[i*(i-1)/2+j-1];
            }

            return 0;
        }

        // Column-major mapping
        void set_column_major(int val,int i,int j){
            if(i>=j){
                B[(j-1)*n-(j-2)*(j-1)/2+i-j]=val;
            }
        }

        int get_column_major(int i,int j){
            if(i>=j){
                return B[(j-1)*n-(j-2)*(j-1)/2+i-j];
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

    cout<<"Enter dimension of lower triangular matrix: ";
    cin>>n;

    LowerTriangular L(n);

    int val;

    cout<<"Enter lower triangular elements:"<<endl;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){

            cin>>val;

            L.set_row_major(val,i,j);
            L.set_column_major(val,i,j);
        }
    }

    cout<<endl<<"Lower Triangular Matrix (Row-Major Storage):";
    L.display_row_major();

    cout<<endl<<"Lower Triangular Matrix (Column-Major Storage):";
    L.display_column_major();

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Row-major value at ("<<i<<","<<j<<") is: "
        <<L.get_row_major(i,j)<<endl;

    cout<<"Column-major value at ("<<i<<","<<j<<") is: "
        <<L.get_column_major(i,j)<<endl;

    return 0;
}