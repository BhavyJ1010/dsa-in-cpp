#include <iostream>
using namespace std;


/*
    Helper function
*/

string lowercase(string s){

    int i=0;

    while(s[i]!='\0'){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]+=32;
        }
        i++;
    }

    return s;
}


/*
    METHOD 1: Using nested loops

    Time Complexity = O(n^2)
*/

void duplicates(string s){

    cout<<endl<<"Duplicates using nested loops: ";

    for(int i=0; s[i]!='\0'; i++){

        bool already_checked=false;

        for(int k=0; k<i; k++){
            if(s[k]==s[i]){
                already_checked=true;
                break;
            }
        }

        if(already_checked){
            continue;
        }

        for(int j=i+1; s[j]!='\0'; j++){
            if(s[i]==s[j]){
                cout<<s[i]<<" ";
                break;
            }
        }
    }

    cout<<endl;
}


/*
    METHOD 2: Using Hashing

    Time Complexity = O(n)
*/

void duplicates_hashing(string s){

    int H[26]={};

    s=lowercase(s);

    for(int i=0; s[i]!='\0'; i++){

        if(s[i]>='a' && s[i]<='z'){
            H[s[i]-'a']++;
        }
    }

    cout<<endl<<"Duplicates using hashing: ";

    for(int i=0; i<26; i++){

        if(H[i]>1){
            cout<<char(i+'a')<<" ";
        }
    }

    cout<<endl;
}


/*
    METHOD 3: Using Bitwise Operations

    Masking:
    Check whether the bit corresponding to a character
    is already ON.

    Merging:
    Turn ON the corresponding bit using OR.
*/

void duplicates_bitwise(string s){

    s=lowercase(s);

    long int H=0;
    long int x;

    cout<<endl<<"Duplicates using bitwise operations: ";

    for(int i=0; s[i]!='\0'; i++){

        if(s[i]>='a' && s[i]<='z'){

            int shift=s[i]-'a';

            x=1;
            x=x<<shift;

            // Masking
            if((H & x)!=0){
                cout<<s[i]<<" ";
            }
            else{
                // Merging
                H=H | x;
            }
        }
    }

    cout<<endl;
}


int main(){

    string s="finding duplicates";

    cout<<endl<<"String: "<<s<<endl;

    duplicates(s);
    duplicates_hashing(s);
    duplicates_bitwise(s);

    cout<<endl;

    return 0;
}