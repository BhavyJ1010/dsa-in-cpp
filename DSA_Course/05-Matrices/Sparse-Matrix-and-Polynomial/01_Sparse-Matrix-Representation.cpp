#include<iostream>
using namespace std;

struct Element{
    int row;
    int col;
    int val;
};

struct Sparse{
    int rows;
    int cols;
    int total;
    Element* ele;
};

void create(Sparse* s){

    cout<<"Enter number of rows and columns: ";
    cin>>s->rows>>s->cols;

    cout<<"Enter number of non-zero elements: ";
    cin>>s->total;

    s->ele=new Element[s->total];

    cout<<"Enter row, column and value of each non-zero element:"<<endl;

    for(int i=0;i<s->total;i++){
        cin>>s->ele[i].row
           >>s->ele[i].col
           >>s->ele[i].val;
    }
}

void display(Sparse s){

    int k=0;

    cout<<endl;

    for(int i=1;i<=s.rows;i++){

        for(int j=1;j<=s.cols;j++){

            if(k<s.total &&
               s.ele[k].row==i &&
               s.ele[k].col==j){

                cout<<s.ele[k].val<<"\t";
                k++;
            }
            else{
                cout<<0<<"\t";
            }
        }

        cout<<endl;
    }
}

int main(){

    Sparse s;

    create(&s);

    cout<<endl<<"Sparse Matrix:";
    display(s);

    delete[] s.ele;

    return 0;
}