#include<iostream>
using namespace std;

const int MAX=10;

void AddEdge(int A[MAX][MAX], int u, int v){
    A[u][v]=1;
}

void Display(int A[MAX][MAX], int n){
    cout<<"Adjacency Matrix:"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void CalculateDegree(int A[MAX][MAX], int n){
    for(int i=0;i<n;i++){
        int inDegree=0;
        int outDegree=0;

        for(int j=0;j<n;j++){
            outDegree+=A[i][j];
            inDegree+=A[j][i];
        }

        cout<<"Vertex "<<i<<": ";
        cout<<"In-degree = "<<inDegree;
        cout<<", Out-degree = "<<outDegree<<endl;
    }
}

int main(){
    int n=4;
    int A[MAX][MAX]={0};

    AddEdge(A,0,1);
    AddEdge(A,0,2);
    AddEdge(A,1,2);
    AddEdge(A,2,0);
    AddEdge(A,2,3);

    Display(A,n);

    cout<<endl<<"Vertex Degrees:"<<endl;
    CalculateDegree(A,n);

    return 0;
}