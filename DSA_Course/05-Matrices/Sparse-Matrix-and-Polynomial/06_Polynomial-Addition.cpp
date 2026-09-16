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

            cout<<endl;

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

        Polynomial* add(Polynomial* p){

            Polynomial* sum=
                new Polynomial(terms+p->terms);

            int i=0;
            int j=0;
            int k=0;

            while(i<terms && j<p->terms){

                if(A[i].exp>p->A[j].exp){

                    sum->A[k]=A[i];

                    i++;
                    k++;
                }

                else if(A[i].exp<p->A[j].exp){

                    sum->A[k]=p->A[j];

                    j++;
                    k++;
                }

                else{

                    int coeff=A[i].coeff+p->A[j].coeff;

                    if(coeff!=0){

                        sum->A[k].coeff=coeff;
                        sum->A[k].exp=A[i].exp;

                        k++;
                    }

                    i++;
                    j++;
                }
            }

            while(i<terms){

                sum->A[k]=A[i];

                i++;
                k++;
            }

            while(j<p->terms){

                sum->A[k]=p->A[j];

                j++;
                k++;
            }

            sum->terms=k;

            return sum;
        }
};

int main(){

    int terms1;
    int terms2;

    cout<<"Enter number of terms in first polynomial: ";
    cin>>terms1;

    Polynomial p1(terms1);

    p1.create();

    cout<<endl<<"First Polynomial:";
    p1.display();

    cout<<endl<<"Enter number of terms in second polynomial: ";
    cin>>terms2;

    Polynomial p2(terms2);

    p2.create();

    cout<<endl<<"Second Polynomial:";
    p2.display();

    Polynomial* sum=p1.add(&p2);

    cout<<endl<<"Sum:";
    sum->display();

    delete sum;

    return 0;
}