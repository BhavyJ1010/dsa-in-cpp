#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#include "../stack.h"

int isOperand(char o){

    if(o=='+' || o=='-' || o=='*' || o=='/' ||
       o=='^' || o=='(' || o==')'){
        return 0;
    }
    else{
        return 1;
    }
}

int instack_precedence(char c){

    if(c=='-' || c=='+'){
        return 2;
    }
    else if(c=='*' || c=='/'){
        return 4;
    }
    else if(c=='^'){
        return 5;
    }
    else if(c=='('){
        return 0;
    }
    else{
        return 0;
    }
}

int outstack_precedence(char c){

    if(c=='-' || c=='+'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 3;
    }
    else if(c=='^'){
        return 6;
    }
    else if(c=='('){
        return 7;
    }
    else if(c==')'){
        return 0;
    }
    else{
        return 0;
    }
}

char* infix_to_postfix(char* infix){

    stack<char> st;

    char* postfix=new char[strlen(infix)+1];

    int i=0;
    int j=0;

    while(infix[i]!='\0'){

        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{

            if(outstack_precedence(infix[i]) >
               instack_precedence(st.StackTop())){

                st.push(infix[i++]);
            }
            else if(outstack_precedence(infix[i]) ==
                    instack_precedence(st.StackTop())){

                st.pop();
                i++;
            }
            else{

                postfix[j++]=st.pop();
            }
        }
    }

    while(!st.isEmpty()){
        postfix[j++]=st.pop();
    }

    postfix[j]='\0';

    return postfix;
}

int main(){

    string s="((a-b)^c^(d/c))+a^b";

    char* c=&s[0];

    char* p=infix_to_postfix(c);

    cout<<p<<endl;

    delete[] p;

    return 0;
}