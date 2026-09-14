#include<iostream>
using namespace std;

class Sparse{
    private:

        struct Element{
            int row;
            int col;
            int val;
        };

        int rows;
        int cols;
        int total;
        Element* ele;

    public:

        Sparse(int rows,int cols,int total){
            this->rows=rows;
            this->cols=cols;
            this->total=total;

            ele=new Element[total];
        }

        ~Sparse(){
            delete[] ele;
        }

        void create(){

            cout<<"Enter row, column and value of each non-zero element:"
                <<endl;

            for(int i=0;i<total;i++){
                cin>>ele[i].row
                   >>ele[i].col
                   >>ele[i].val;
            }
        }

        void display(){

            int k=0;

            cout<<endl;

            for(int i=1;i<=rows;i++){

                for(int j=1;j<=cols;j++){

                    if(k<total &&
                       ele[k].row==i &&
                       ele[k].col==j){

                        cout<<ele[k].val<<"\t";
                        k++;
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

    int rows;
    int cols;
    int total;

    cout<<"Enter number of rows and columns: ";
    cin>>rows>>cols;

    cout<<"Enter number of non-zero elements: ";
    cin>>total;

    Sparse s(rows,cols,total);

    s.create();

    cout<<endl<<"Sparse Matrix:";
    s.display();

    return 0;
}