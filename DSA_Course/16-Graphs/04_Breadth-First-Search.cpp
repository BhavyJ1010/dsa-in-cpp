#include<iostream>
#include<queue>
using namespace std;

const int MAX=10;

void BFS(int start, int A[MAX][MAX], int n){
    int visited[MAX]={0};
    queue<int> Q;

    visited[start]=1;
    cout<<start<<" ";
    Q.push(start);

    while(!Q.empty()){
        int u=Q.front();
        Q.pop();

        for(int v=0;v<n;v++){
            if(A[u][v]==1 && visited[v]==0){
                cout<<v<<" ";
                visited[v]=1;
                Q.push(v);
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

    cout<<"BFS starting from vertex 0: ";
    BFS(0,A,n);

    cout<<"BFS starting from vertex 3: ";
    BFS(3,A,n);

    return 0;
}