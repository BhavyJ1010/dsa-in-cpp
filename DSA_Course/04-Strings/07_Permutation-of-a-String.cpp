#include <iostream>
using namespace std;


/*
    METHOD 1: Using flag array and result array

    flag[i] tells whether the character at position i
    has already been used.
*/

void permutation_flag(string s, int k){

    static int flag[20]={};
    static char result[20];

    if(s[k]=='\0'){
        result[k]='\0';
        cout<<result<<endl;
        return;
    }

    for(int i=0; s[i]!='\0'; i++){

        if(flag[i]==0){

            result[k]=s[i];
            flag[i]=1;

            permutation_flag(s,k+1);

            flag[i]=0;
        }
    }
}


/*
    METHOD 2: Using swapping

    Characters are swapped into the current position.
    After recursion, the swap is undone to restore
    the original string.

    This is backtracking.
*/

void permutation_swap(string &s, int l, int h){

    if(l==h){
        cout<<s<<endl;
        return;
    }

    for(int i=l; i<=h; i++){

        char temp=s[l];
        s[l]=s[i];
        s[i]=temp;

        permutation_swap(s,l+1,h);

        temp=s[l];
        s[l]=s[i];
        s[i]=temp;
    }
}


int length(string s){

    int i=0;

    while(s[i]!='\0'){
        i++;
    }

    return i;
}


int main(){

    string s="ABC";

    cout<<endl<<"Using flag and result array:"<<endl;
    permutation_flag(s,0);

    cout<<endl<<"Using swapping:"<<endl;
    permutation_swap(s,0,length(s)-1);

    cout<<endl;

    return 0;
}