#include<iostream>
#include<stack>
using namespace std;

const int MAX=10;

void RecursiveDFS(int u, int A[MAX][MAX], int n, int visited[]){
    cout<<u<<" ";
    visited[u]=1;

    for(int v=0;v<n;v++){
        if(A[u][v]==1 && visited[v]==0){
            RecursiveDFS(v,A,n,visited);
        }
    }
}

void DFS(int start, int A[MAX][MAX], int n){
    int visited[MAX]={0};

    RecursiveDFS(start,A,n,visited);
    cout<<endl;
}

void IterativeDFS(int start, int A[MAX][MAX], int n){
    int visited[MAX]={0};
    stack<int> stk;

    stk.push(start);
    visited[start]=1;

    while(!stk.empty()){
        int u=stk.top();
        stk.pop();

        cout<<u<<" ";

        // Push neighbours in reverse order
        for(int v=n-1;v>=0;v--){
            if(A[u][v]==1 && visited[v]==0){
                visited[v]=1;
                stk.push(v);
            }
        }
    }

    cout<<endl;
}

int main(){
    int A[MAX][MAX]={0};
    int n=7;

    A[0][1]=A[1][0]=1;
    A[0][2]=A[2][0]=1;
    A[1][3]=A[3][1]=1;
    A[1][4]=A[4][1]=1;
    A[2][5]=A[5][2]=1;
    A[2][6]=A[6][2]=1;

    cout<<"Recursive DFS: ";
    DFS(0,A,n);

    cout<<"Iterative DFS: ";
    IterativeDFS(0,A,n);

    return 0;
}