#include<iostream>
using namespace std;

class Toeplitz{
    private:
        int n;
        int* A;

    public:
        Toeplitz(int n){
            this->n=n;
            A=new int[2*n-1];
        }

        ~Toeplitz(){
            delete[] A;
        }

        void set(int val,int i,int j){

            if(i<=j){
                A[j-i]=val;
            }
            else{
                A[n+i-j-1]=val;
            }
        }

        int get(int i,int j){

            if(i<=j){
                return A[j-i];
            }
            else{
                return A[n+i-j-1];
            }
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

    cout<<"Enter dimension of Toeplitz matrix: ";
    cin>>n;

    Toeplitz T(n);

    int val;

    cout<<"Enter first row elements:"<<endl;

    for(int j=1;j<=n;j++){
        cin>>val;
        T.set(val,1,j);
    }

    cout<<"Enter elements below main diagonal:"<<endl;

    for(int i=2;i<=n;i++){
        cin>>val;
        T.set(val,i,1);
    }

    cout<<endl<<"Toeplitz Matrix:";
    T.display();

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Value at ("<<i<<","<<j<<") is: "
        <<T.get(i,j)<<endl;

    return 0;
}