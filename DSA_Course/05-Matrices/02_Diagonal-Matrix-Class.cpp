#include<iostream>
using namespace std;

class Diagonal{

    private:
        int n;
        int* A;

    public:

        Diagonal(int n){
            this->n=n;
            A=new int[n];
        }

        ~Diagonal(){
            delete[] A;
        }

        void set(int val, int i, int j){
            if(i==j){
                A[i-1]=val;
            }
        }

        int get(int i, int j){
            if(i==j){
                return A[i-1];
            }

            return 0;
        }

        void display(){

            cout<<endl;

            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){

                    if(i==j){
                        cout<<A[i-1]<<"\t";
                    }
                    else{
                        cout<<0<<"\t";
                    }
                }

                cout<<endl;
            }
        }
};

int main(){

    int dim;

    cout<<"Enter dimension of diagonal matrix: ";
    cin>>dim;

    Diagonal D(dim);

    int choice=-1;

    while(choice!=0){

        cout<<endl<<"Enter Choice of Operation: "
            <<endl<<"1. SET diagonal values"
            <<endl<<"2. GET a value"
            <<endl<<"3. DISPLAY matrix"
            <<endl<<"0. EXIT"
            <<endl<<"Choice: ";

        cin>>choice;

        switch(choice){

            case 1:{
                int val;

                cout<<"Enter all diagonal values: "<<endl;

                for(int i=1; i<=dim; i++){
                    cin>>val;
                    D.set(val,i,i);
                }

                break;
            }

            case 2:{
                int i,j;

                cout<<"Enter index (i, j): ";
                cin>>i>>j;

                cout<<"Value at ("<<i<<","<<j<<") is: "
                    <<D.get(i,j)<<endl;

                break;
            }

            case 3:
                D.display();
                break;

            case 0:
                break;

            default:
                cout<<"Invalid choice."<<endl;
        }
    }

    return 0;
}