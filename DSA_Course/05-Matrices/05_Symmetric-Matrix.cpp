#include<iostream>
using namespace std;

class Symmetric{
    private:
        int n;
        int* A;

    public:
        Symmetric(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }

        ~Symmetric(){
            delete[] A;
        }

        void set(int val,int i,int j){
            if(i>=j){
                A[i*(i-1)/2+j-1]=val;
            }
            else{
                A[j*(j-1)/2+i-1]=val;
            }
        }

        int get(int i,int j){
            if(i>=j){
                return A[i*(i-1)/2+j-1];
            }
            else{
                return A[j*(j-1)/2+i-1];
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

    cout<<"Enter dimension of symmetric matrix: ";
    cin>>n;

    Symmetric S(n);

    int val;

    cout<<"Enter lower triangular elements:"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>val;
            S.set(val,i,j);
        }
    }

    cout<<endl<<"Symmetric Matrix:";
    S.display();

    int i,j;

    cout<<endl<<"Enter index (i, j) to get value: ";
    cin>>i>>j;

    cout<<"Value at ("<<i<<","<<j<<") is: "
        <<S.get(i,j)<<endl;

    return 0;
}