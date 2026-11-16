#include<iostream>
using namespace std;

const int SIZE=10;

int Hash(int key){
    return key%SIZE;
}

int Insert(int H[], int key){
    int index=Hash(key);

    for(int i=0;i<SIZE;i++){
        int pos=(index+i)%SIZE;

        if(H[pos]==-1){
            H[pos]=key;
            return pos;
        }

        if(H[pos]==key){
            return pos;
        }
    }

    return -1;
}

int Search(int H[], int key){
    int index=Hash(key);

    for(int i=0;i<SIZE;i++){
        int pos=(index+i)%SIZE;

        if(H[pos]==-1){
            return -1;
        }

        if(H[pos]==key){
            return pos;
        }
    }

    return -1;
}

void Display(int H[]){
    for(int i=0;i<SIZE;i++){
        cout<<i<<" : "<<H[i]<<endl;
    }
}

int main(){
    int HT[SIZE];

    for(int i=0;i<SIZE;i++){
        HT[i]=-1;
    }

    int A[]={26,30,45,23,25,43,74,19,29};
    int n=sizeof(A)/sizeof(A[0]);

    for(int i=0;i<n;i++){
        Insert(HT,A[i]);
    }

    Display(HT);

    int key=25;
    cout<<"Key "<<key<<" found at index: "<<Search(HT,key)<<endl;

    key=35;
    cout<<"Key "<<key<<" found at index: "<<Search(HT,key)<<endl;

    return 0;
}