#include<iostream>
#include<string>
using namespace std;

#include "stack.h"

int main(){

    string s="{(z[x+y])/[((p)^q)10r]}";

    stack<char> st;

    int i=0;

    while(s[i]!='\0'){

        char c=s[i];

        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }
        else if(c==')' || c==']' || c=='}'){

            if(st.isEmpty()){
                cout<<"Parenthesis Don't match";
                return 0;
            }

            char balance=st.pop();

            if(!(
                (c==')' && balance=='(') ||
                (c==']' && balance=='[') ||
                (c=='}' && balance=='{')
            )){
                cout<<"Parenthesis Don't match";
                return 0;
            }
        }

        i++;
    }

    if(st.isEmpty()){
        cout<<"Parenthesis Matches";
    }
    else{
        cout<<"Parenthesis Don't match";
    }

    return 0;
}