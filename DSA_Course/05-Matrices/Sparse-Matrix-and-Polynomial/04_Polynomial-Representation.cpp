#include<iostream>
using namespace std;

class Polynomial{
    private:

        struct Term{
            int coeff;
            int exp;
        };

        int terms;
        Term* A;

    public:

        Polynomial(int terms){
            this->terms=terms;

            A=new Term[terms];
        }

        ~Polynomial(){
            delete[] A;
        }

        void create(){

            cout<<"Enter coefficient and exponent for each term "
                <<"(highest exponent first):"<<endl;

            for(int i=0;i<terms;i++){
                cin>>A[i].coeff>>A[i].exp;
            }
        }

        void display(){

            cout<<endl<<"Polynomial: ";

            for(int i=0;i<terms;i++){

                if(i>0 && A[i].coeff>=0){
                    cout<<"+";
                }

                cout<<A[i].coeff;

                if(A[i].exp>0){

                    cout<<"x";

                    if(A[i].exp>1){
                        cout<<"^"<<A[i].exp;
                    }
                }
            }

            cout<<endl;
        }
};

int main(){

    int terms;

    cout<<"Enter number of terms: ";
    cin>>terms;

    Polynomial p(terms);

    p.create();

    p.display();

    return 0;
}