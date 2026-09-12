#include<iostream>
using namespace std;

class Matrix{
    private:
        int A[10][10];
        int rows;
        int cols;

    public:

        void create(){
            cout<<"Enter number of rows and columns: ";
            cin>>rows>>cols;

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

        void add(Matrix M1,Matrix M2){
            if(M1.rows!=M2.rows || M1.cols!=M2.cols){
                cout<<"Addition is not possible."<<endl;
                return;
            }

            rows=M1.rows;
            cols=M1.cols;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    A[i][j]=M1.A[i][j]+M2.A[i][j];
                }
            }
        }

        void subtract(Matrix M1,Matrix M2){
            if(M1.rows!=M2.rows || M1.cols!=M2.cols){
                cout<<"Subtraction is not possible."<<endl;
                return;
            }

            rows=M1.rows;
            cols=M1.cols;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    A[i][j]=M1.A[i][j]-M2.A[i][j];
                }
            }
        }

        void multiply(Matrix M1,Matrix M2){
            if(M1.cols!=M2.rows){
                cout<<"Multiplication is not possible."<<endl;
                return;
            }

            rows=M1.rows;
            cols=M2.cols;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    A[i][j]=0;

                    for(int k=0;k<M1.cols;k++){
                        A[i][j]+=M1.A[i][k]*M2.A[k][j];
                    }
                }
            }
        }

        void transpose(Matrix M){
            rows=M.cols;
            cols=M.rows;

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    A[i][j]=M.A[j][i];
                }
            }
        }
};

int main(){

    Matrix M1,M2,M3;

    int choice=1;

    while(choice!=0){

        cout<<endl;
        cout<<"1. Create Matrix 1"<<endl;
        cout<<"2. Create Matrix 2"<<endl;
        cout<<"3. Display Matrix 1"<<endl;
        cout<<"4. Display Matrix 2"<<endl;
        cout<<"5. Add Matrix 1 and Matrix 2"<<endl;
        cout<<"6. Subtract Matrix 2 from Matrix 1"<<endl;
        cout<<"7. Multiply Matrix 1 and Matrix 2"<<endl;
        cout<<"8. Transpose Matrix 1"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                M1.create();
                break;

            case 2:
                M2.create();
                break;

            case 3:
                cout<<"Matrix 1:";
                M1.display();
                break;

            case 4:
                cout<<"Matrix 2:";
                M2.display();
                break;

            case 5:
                M3.add(M1,M2);
                cout<<"Sum:";
                M3.display();
                break;

            case 6:
                M3.subtract(M1,M2);
                cout<<"Difference:";
                M3.display();
                break;

            case 7:
                M3.multiply(M1,M2);
                cout<<"Product:";
                M3.display();
                break;

            case 8:
                M3.transpose(M1);
                cout<<"Transpose of Matrix 1:";
                M3.display();
                break;

            case 0:
                break;

            default:
                cout<<"Invalid choice."<<endl;
        }
    }

    return 0;
}