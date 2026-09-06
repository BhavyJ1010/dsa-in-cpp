#include <iostream>
using namespace std;

void equal(string A, string B){

    int i=0;

    while(A[i]!='\0' && B[i]!='\0'){
        if(A[i]!=B[i]){
            break;
        }
        i++;
    }

    if(A[i]<B[i]){
        cout<<endl<<"smaller";
    }
    else if(A[i]>B[i]){
        cout<<endl<<"larger";
    }
    else{
        cout<<endl<<"equal";
    }
}

bool palindrome(string s){

    int j=0;

    while(s[j]!='\0') j++;
    j--;

    for(int i=0; i<j; i++, j--){
        if(s[i]!=s[j]){
            return false;
        }
    }

    return true;
}

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

int main(){

    string s1=lowercase("Madame");
    string s2=lowercase("madam");

    cout<<endl<<"Comparing strings:";
    equal(s1, s2);

    cout<<endl;

    if(palindrome(s1)){
        cout<<endl<<s1<<" is a palindrome.";
    }
    else{
        cout<<endl<<s1<<" is not a palindrome.";
    }

    cout<<endl;

    return 0;
}