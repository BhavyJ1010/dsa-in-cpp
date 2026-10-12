#include<iostream>
#include<string>
using namespace std;

#include "stack.h"

bool isOperand(char c){
    return !(c=='+' || c=='-' || c=='*' || c=='/');
}

float evaluate(char op,float op1,float op2){

    if(op=='+')
        return op1+op2;

    if(op=='-')
        return op1-op2;

    if(op=='*')
        return op1*op2;

    if(op=='/')
        return op1/op2;

    return 0;
}

float evaluate_postfix(string postfix){

    stack<float> st;

    for(int i=0; postfix[i]!='\0'; i++){

        if(isOperand(postfix[i])){
            st.push(postfix[i]-'0');
        }
        else{

            float op1=st.pop();
            float op2=st.pop();

            float result=evaluate(postfix[i],op2,op1);

            st.push(result);
        }
    }

    return st.pop();
}

int main(){

    string postfix="42+83-*";

    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Result: "<<evaluate_postfix(postfix)<<endl;

    return 0;
}