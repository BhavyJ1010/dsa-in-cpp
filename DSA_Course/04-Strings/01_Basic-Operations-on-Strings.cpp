#include <iostream>
using namespace std;

int length(string s){
    int length=0;
    while(s[length]!='\0') length++;
    return length;
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

string uppercase(string s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }
        i++;
    }
    return s;
}

string togglecase(string s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]+=32;
        }
        else if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }
        i++;
    }
    return s;
}

bool is_alphabet(char c){

    if(c>='A' && c<='Z'){
        return true;
    }
    else if(c>='a' && c<='z'){
        return true;
    }
    else{
        return false;
    }
}

int count_words(string s){
    int i=0, count=0;
    bool in_word=false;

    while(s[i]!='\0'){
        if(is_alphabet(s[i])){
            if(!in_word){
                count++;
                in_word=true;
            }
        }
        else{
            in_word=false;
        }
        i++;
    }

    return count;
}

int count_space(string s){
    int i=0, count=0;

    while(s[i]!='\0'){
        if(s[i]==' '){
            count++;
        }
        i++;
    }

    return count;
}

int count_vowel(string s){
    int i=0, count=0;
    s=lowercase(s);

    while(s[i]!='\0'){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||
           s[i]=='o' || s[i]=='u'){
            count++;
        }
        i++;
    }

    return count;
}

int count_consonant(string s){
    int i=0, count=0;
    s=lowercase(s);

    while(s[i]!='\0'){
        if(is_alphabet(s[i])){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' &&
               s[i]!='o' && s[i]!='u'){
                count++;
            }
        }
        i++;
    }

    return count;
}

int main(){

    string s="Understanding - Strings";

    cout<<endl;
    cout<<"string: "<<s<<endl;
    cout<<"length = "<<length(s)<<endl;
    cout<<"Smallcase: "<<lowercase(s)<<endl;
    cout<<"Uppercase: "<<uppercase(s)<<endl;
    cout<<"Togglecase: "<<togglecase(s)<<endl;
    cout<<"Words = "<<count_words(s)<<endl;
    cout<<"Vowel = "<<count_vowel(s)<<endl;
    cout<<"Consonent = "<<count_consonant(s)<<endl;
    cout<<endl;

    return 0;
}