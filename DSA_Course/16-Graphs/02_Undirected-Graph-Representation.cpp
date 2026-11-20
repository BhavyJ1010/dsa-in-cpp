#include<iostream>
#include<vector>
using namespace std;

const int MAX=10;

void AddEdgeMatrix(int A[MAX][MAX], int u, int v){
    A[u][v]=1;
    A[v][u]=1;
}

void AddEdgeList(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DisplayMatrix(int A[MAX][MAX], int n){
    cout<<"Adjacency Matrix:"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DisplayList(vector<int> adj[], int n){
    cout<<"Adjacency List:"<<endl;

    for(int i=0;i<n;i++){
        cout<<i<<" : ";

        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main(){
    int n=5;

    int A[MAX][MAX]={0};
    vector<int> adj[MAX];

    AddEdgeMatrix(A,0,1);
    AddEdgeMatrix(A,0,2);
    AddEdgeMatrix(A,1,2);
    AddEdgeMatrix(A,1,3);
    AddEdgeMatrix(A,3,4);

    AddEdgeList(adj,0,1);
    AddEdgeList(adj,0,2);
    AddEdgeList(adj,1,2);
    AddEdgeList(adj,1,3);
    AddEdgeList(adj,3,4);

    DisplayMatrix(A,n);
    cout<<endl;
    DisplayList(adj,n);

    return 0;
}