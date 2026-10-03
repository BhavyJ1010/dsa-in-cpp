#include<iostream>
using namespace std;

struct node{
    int col;
    int data;
    node* next;
};

node** create(int total_rows){

    node** row = new node*[total_rows];

    for(int i = 0; i < total_rows; i++){

        row[i] = NULL;

        int total_columns;

        cout << "Enter non-zero elements in row "
             << i + 1 << ": ";
        cin >> total_columns;

        node* last = NULL;

        for(int j = 0; j < total_columns; j++){

            node* t = new node;

            cout << "Enter [column, value]: ";
            cin >> t->col >> t->data;

            t->next = NULL;

            if(row[i] == NULL)
                row[i] = t;
            else
                last->next = t;

            last = t;
        }
    }

    return row;
}

void display(node** row, int total_rows, int total_columns){

    for(int i = 0; i < total_rows; i++){

        node* p = row[i];

        for(int j = 0; j < total_columns; j++){

            if(p != NULL && p->col == j){
                cout << p->data << "\t";
                p = p->next;
            }
            else{
                cout << "0\t";
            }
        }

        cout << endl;
    }

    cout << endl;
}

node** add(node** row1, node** row2, int total_rows){

    // Each row's linked list should be stored
    // in increasing order of column number.

    node** sum = new node*[total_rows];

    for(int i = 0; i < total_rows; i++){

        node* p = row1[i];
        node* q = row2[i];

        sum[i] = NULL;
        node* last = NULL;

        while(p && q){

            node* t = new node;
            t->next = NULL;

            if(p->col < q->col){

                t->col = p->col;
                t->data = p->data;

                p = p->next;
            }

            else if(p->col > q->col){

                t->col = q->col;
                t->data = q->data;

                q = q->next;
            }

            else{

                t->col = p->col;
                t->data = p->data + q->data;

                p = p->next;
                q = q->next;
            }

            if(t->data != 0){

                if(sum[i] == NULL)
                    sum[i] = t;
                else
                    last->next = t;

                last = t;
            }
            else{
                delete t;
            }
        }

        while(p){

            node* t = new node;

            t->col = p->col;
            t->data = p->data;
            t->next = NULL;

            if(sum[i] == NULL)
                sum[i] = t;
            else
                last->next = t;

            last = t;
            p = p->next;
        }

        while(q){

            node* t = new node;

            t->col = q->col;
            t->data = q->data;
            t->next = NULL;

            if(sum[i] == NULL)
                sum[i] = t;
            else
                last->next = t;

            last = t;
            q = q->next;
        }
    }

    return sum;
}

int main(){

    node** sparse1 = create(5);

    display(sparse1, 5, 5);

    node** sparse2 = create(5);

    display(sparse2, 5, 5);

    node** sum = add(sparse1, sparse2, 5);

    display(sum, 5, 5);

    return 0;
}