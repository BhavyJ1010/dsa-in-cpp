#include <iostream>
using namespace std;

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

bool anagram(string A, string B){

    A=lowercase(A);
    B=lowercase(B);

    int H[26]={};

    int i=0;

    while(A[i]!='\0'){
        if(A[i]>='a' && A[i]<='z'){
            H[A[i]-'a']++;
        }
        i++;
    }

    i=0;

    while(B[i]!='\0'){
        if(B[i]>='a' && B[i]<='z'){
            H[B[i]-'a']--;
        }
        i++;
    }

    for(i=0; i<26; i++){
        if(H[i]!=0){
            return false;
        }
    }

    return true;
}

int main(){

    string A="listen";
    string B="silent";

    cout<<endl<<"String 1: "<<A;
    cout<<endl<<"String 2: "<<B;

    if(anagram(A,B)){
        cout<<endl<<"Both strings are anagrams.";
    }
    else{
        cout<<endl<<"Both strings are not anagrams.";
    }

    cout<<endl;

    return 0;
}