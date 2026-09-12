#include<iostream>
using namespace std;

class Matrix{
    private:
        int rows;
        int cols;
        int** A;

    public:

        Matrix(int rows,int cols){
            this->rows=rows;
            this->cols=cols;

            A=new int*[rows];

            for(int i=0;i<rows;i++){
                A[i]=new int[cols];
            }
        }

        ~Matrix(){

            for(int i=0;i<rows;i++){
                delete[] A[i];
            }

            delete[] A;
        }

        void set(int val,int i,int j){
            A[i][j]=val;
        }

        int get(int i,int j){
            return A[i][j];
        }

        void create(){

            cout<<"Enter matrix elements:"<<endl;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin>>A[i][j];
                }
            }
        }

        void display(){

            cout<<endl;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cout<<A[i][j]<<"\t";
                }
                cout<<endl;
            }
        }

        Matrix* add(Matrix* M){

            if(rows!=M->rows || cols!=M->cols){
                return NULL;
            }

            Matrix* R=new Matrix(rows,cols);

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    R->A[i][j]=A[i][j]+M->A[i][j];
                }
            }

            return R;
        }

        Matrix* subtract(Matrix* M){

            if(rows!=M->rows || cols!=M->cols){
                return NULL;
            }

            Matrix* R=new Matrix(rows,cols);

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    R->A[i][j]=A[i][j]-M->A[i][j];
                }
            }

            return R;
        }

        Matrix* multiply(Matrix* M){

            if(cols!=M->rows){
                return NULL;
            }

            Matrix* R=new Matrix(rows,M->cols);

            for(int i=0;i<rows;i++){
                for(int j=0;j<M->cols;j++){

                    R->A[i][j]=0;

                    for(int k=0;k<cols;k++){
                        R->A[i][j]+=A[i][k]*M->A[k][j];
                    }
                }
            }

            return R;
        }

        Matrix* transpose(){

            Matrix* R=new Matrix(cols,rows);

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    R->A[j][i]=A[i][j];
                }
            }

            return R;
        }
};

int main(){

    int r1,c1,r2,c2;

    cout<<"Enter rows and columns of Matrix 1: ";
    cin>>r1>>c1;

    Matrix M1(r1,c1);

    M1.create();

    cout<<"Enter rows and columns of Matrix 2: ";
    cin>>r2>>c2;

    Matrix M2(r2,c2);

    M2.create();

    cout<<endl<<"Matrix 1:";
    M1.display();

    cout<<endl<<"Matrix 2:";
    M2.display();

    Matrix* R;

    R=M1.add(&M2);

    if(R!=NULL){
        cout<<endl<<"Addition:";
        R->display();
        delete R;
    }
    else{
        cout<<endl<<"Addition is not possible.";
    }

    R=M1.subtract(&M2);

    if(R!=NULL){
        cout<<endl<<"Subtraction:";
        R->display();
        delete R;
    }
    else{
        cout<<endl<<"Subtraction is not possible.";
    }

    R=M1.multiply(&M2);

    if(R!=NULL){
        cout<<endl<<"Multiplication:";
        R->display();
        delete R;
    }
    else{
        cout<<endl<<"Multiplication is not possible.";
    }

    R=M1.transpose();

    cout<<endl<<"Transpose of Matrix 1:";
    R->display();

    delete R;

    return 0;
}