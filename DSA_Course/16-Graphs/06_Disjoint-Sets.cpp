#include<iostream>
using namespace std;

const int SIZE=7;

int parent[SIZE];
int rankSet[SIZE];

void Initialize(){
    for(int i=0;i<SIZE;i++){
        parent[i]=i;
        rankSet[i]=0;
    }
}

int Find(int x){
    if(parent[x]!=x){
        parent[x]=Find(parent[x]);
    }

    return parent[x];
}

void Union(int u, int v){
    int rootU=Find(u);
    int rootV=Find(v);

    if(rootU==rootV){
        return;
    }

    if(rankSet[rootU]<rankSet[rootV]){
        parent[rootU]=rootV;
    }
    else if(rankSet[rootU]>rankSet[rootV]){
        parent[rootV]=rootU;
    }
    else{
        parent[rootV]=rootU;
        rankSet[rootU]++;
    }
}

bool Connected(int u, int v){
    return Find(u)==Find(v);
}

int main(){
    Initialize();

    Union(0,1);
    Union(1,2);
    Union(3,4);
    Union(5,6);

    cout<<"Are 0 and 2 connected? ";
    cout<<(Connected(0,2)?"Yes":"No")<<endl;

    cout<<"Are 0 and 4 connected? ";
    cout<<(Connected(0,4)?"Yes":"No")<<endl;

    Union(2,4);

    cout<<"After Union(2,4):"<<endl;

    cout<<"Are 0 and 4 connected? ";
    cout<<(Connected(0,4)?"Yes":"No")<<endl;

    cout<<"Representative of 4: "<<Find(4)<<endl;

    return 0;
}