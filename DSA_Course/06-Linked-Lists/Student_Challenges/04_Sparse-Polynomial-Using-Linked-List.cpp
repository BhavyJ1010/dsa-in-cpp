#include<iostream>
using namespace std;

struct poly{
    int coeff;
    int exp;
    poly* next;
};

poly* create(){

    int n;

    cout << "Enter total number of terms: ";
    cin >> n;

    poly* head = NULL;
    poly* last = NULL;

    cout << "Enter terms in decreasing order of exponent:\n";

    for(int i = 0; i < n; i++){

        poly* t = new poly;

        cout << "Enter coefficient and exponent: ";
        cin >> t->coeff >> t->exp;

        t->next = NULL;

        if(head == NULL)
            head = t;
        else
            last->next = t;

        last = t;
    }

    return head;
}

void display(poly* p){

    cout << endl;

    while(p){

        if(p->exp == 0)
            cout << p->coeff;
        else
            cout << "(" << p->coeff << ")x^" << p->exp;

        if(p->next)
            cout << " + ";

        p = p->next;
    }

    cout << endl;
}

int evaluate(poly* p, int x){

    int result = 0;

    while(p){

        int power = 1;

        for(int i = 0; i < p->exp; i++)
            power *= x;

        result += p->coeff * power;

        p = p->next;
    }

    return result;
}

poly* add(poly* p, poly* q){

    poly* sum = NULL;
    poly* last = NULL;

    while(p && q){

        poly* t = new poly;
        t->next = NULL;

        if(p->exp > q->exp){

            t->coeff = p->coeff;
            t->exp = p->exp;

            p = p->next;
        }

        else if(p->exp < q->exp){

            t->coeff = q->coeff;
            t->exp = q->exp;

            q = q->next;
        }

        else{

            t->coeff = p->coeff + q->coeff;
            t->exp = p->exp;

            p = p->next;
            q = q->next;
        }

        if(t->coeff != 0){

            if(sum == NULL)
                sum = t;
            else
                last->next = t;

            last = t;
        }

        else{
            delete t;
        }
    }

    while(p){

        poly* t = new poly;

        t->coeff = p->coeff;
        t->exp = p->exp;
        t->next = NULL;

        if(sum == NULL)
            sum = t;
        else
            last->next = t;

        last = t;

        p = p->next;
    }

    while(q){

        poly* t = new poly;

        t->coeff = q->coeff;
        t->exp = q->exp;
        t->next = NULL;

        if(sum == NULL)
            sum = t;
        else
            last->next = t;

        last = t;

        q = q->next;
    }

    return sum;
}

int main(){

    cout << "Polynomial 1\n";
    poly* p = create();

    cout << "\nPolynomial 1: ";
    display(p);

    cout << "\nPolynomial 2\n";
    poly* q = create();

    cout << "\nPolynomial 2: ";
    display(q);

    int x;

    cout << "\nEnter value of x: ";
    cin >> x;

    cout << "Value of Polynomial 1 = "
         << evaluate(p, x) << endl;

    cout << "Value of Polynomial 2 = "
         << evaluate(q, x) << endl;

    poly* sum = add(p, q);

    cout << "\nSum: ";
    display(sum);

    return 0;
}