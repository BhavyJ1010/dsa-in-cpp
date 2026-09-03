#include <iostream>
using namespace std;

int length(string s){
    int i=0;
    while(s[i]!='\0') i++;
    return i;
}

bool valid(string s){
    for(int i=0; i<length(s); i++){
        if(!((s[i]>='a' && s[i]<='z') ||
             (s[i]>='A' && s[i]<='Z') ||
             (s[i]>='0' && s[i]<='9'))){
            return false;
        }
    }

    return true;
}

int main(){

    string s;
    cout<<endl<<"enter a password (only a-z, A-Z, 0-9 allowed): "<<endl;
    cin>>s;

    if(valid(s)){
        cout<<endl<<s<<" is valid";
    }
    else{
        cout<<endl<<"password isn't valid."<<endl;
    }

    return 0;
}