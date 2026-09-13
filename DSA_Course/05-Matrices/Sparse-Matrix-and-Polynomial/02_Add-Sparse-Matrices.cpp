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

Sparse* add(Sparse* s1,Sparse* s2){

    if(s1->rows!=s2->rows || s1->cols!=s2->cols){
        return NULL;
    }

    Sparse* sum=new Sparse;

    sum->rows=s1->rows;
    sum->cols=s1->cols;
    sum->ele=new Element[s1->total+s2->total];

    int i=0;
    int j=0;
    int k=0;

    while(i<s1->total && j<s2->total){

        if(s1->ele[i].row<s2->ele[j].row ||
          (s1->ele[i].row==s2->ele[j].row &&
           s1->ele[i].col<s2->ele[j].col)){

            sum->ele[k]=s1->ele[i];
            i++;
            k++;
        }

        else if(s2->ele[j].row<s1->ele[i].row ||
               (s2->ele[j].row==s1->ele[i].row &&
                s2->ele[j].col<s1->ele[i].col)){

            sum->ele[k]=s2->ele[j];
            j++;
            k++;
        }

        else{

            int value=s1->ele[i].val+s2->ele[j].val;

            if(value!=0){
                sum->ele[k].row=s1->ele[i].row;
                sum->ele[k].col=s1->ele[i].col;
                sum->ele[k].val=value;
                k++;
            }

            i++;
            j++;
        }
    }

    while(i<s1->total){
        sum->ele[k]=s1->ele[i];
        i++;
        k++;
    }

    while(j<s2->total){
        sum->ele[k]=s2->ele[j];
        j++;
        k++;
    }

    sum->total=k;

    return sum;
}

int main(){

    Sparse s1,s2;

    cout<<"Enter first sparse matrix:"<<endl;
    create(&s1);

    cout<<endl<<"Enter second sparse matrix:"<<endl;
    create(&s2);

    cout<<endl<<"First Matrix:";
    display(s1);

    cout<<endl<<"Second Matrix:";
    display(s2);

    Sparse* sum=add(&s1,&s2);

    if(sum!=NULL){

        cout<<endl<<"Sum:";
        display(*sum);

        delete[] sum->ele;
        delete sum;
    }
    else{
        cout<<endl<<"Addition is not possible.";
    }

    delete[] s1.ele;
    delete[] s2.ele;

    return 0;
}