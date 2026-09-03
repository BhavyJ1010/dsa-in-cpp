#include <iostream>
using namespace std;

string Reverse1(string s){
    int i=0, j=0;
    char temp;

    while(s[j]!='\0') j++;
    j--;

    while(i<j){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;

        i++;
        j--;
    }

    return s;
}

string Reverse2(string s){
    int i=0, j=0;

    while(s[j]!='\0') j++;
    j--;

    char r[100];

    while(s[i]!='\0'){
        r[i]=s[j];
        i++;
        j--;
    }

    r[i]='\0';

    return r;
}

int main(){

    string s="reversE";

    cout<<endl<<"Original string: "<<s;
    cout<<endl<<"Reverse using swapping: "<<Reverse1(s);
    cout<<endl<<"Reverse using another array: "<<Reverse2(s);

    cout<<endl;

    return 0;
}