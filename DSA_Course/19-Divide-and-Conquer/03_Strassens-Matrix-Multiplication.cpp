#include<iostream>
#include<vector>
using namespace std;

using Matrix = vector<vector<long long>>;

Matrix Add(Matrix A, Matrix B)
{
    int n = A.size();
    Matrix C(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

Matrix Subtract(Matrix A, Matrix B)
{
    int n = A.size();
    Matrix C(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

Matrix Strassen(Matrix A, Matrix B)
{
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));

    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;

    Matrix A11(k, vector<long long>(k));
    Matrix A12(k, vector<long long>(k));
    Matrix A21(k, vector<long long>(k));
    Matrix A22(k, vector<long long>(k));

    Matrix B11(k, vector<long long>(k));
    Matrix B12(k, vector<long long>(k));
    Matrix B21(k, vector<long long>(k));
    Matrix B22(k, vector<long long>(k));

    // Divide both matrices into four parts

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculate seven products

    Matrix M1 = Strassen(Add(A11, A22), Add(B11, B22));

    Matrix M2 = Strassen(Add(A21, A22), B11);

    Matrix M3 = Strassen(A11, Subtract(B12, B22));

    Matrix M4 = Strassen(A22, Subtract(B21, B11));

    Matrix M5 = Strassen(Add(A11, A12), B22);

    Matrix M6 = Strassen(Subtract(A21, A11), Add(B11, B12));

    Matrix M7 = Strassen(Subtract(A12, A22), Add(B21, B22));

    // Calculate four parts of the result matrix

    Matrix C11 = Add(Subtract(Add(M1, M4), M5), M7);

    Matrix C12 = Add(M3, M5);

    Matrix C21 = Add(M2, M4);

    Matrix C22 = Add(Subtract(Add(M1, M3), M2), M6);

    // Combine the four parts

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

int main()
{
    int n;

    cout << "Enter order of square matrices: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid matrix size";
        return 0;
    }

    Matrix A(n, vector<long long>(n));
    Matrix B(n, vector<long long>(n));

    cout << "Enter elements of first matrix:\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j];

    // Pad matrices to the next power of 2 if required

    int size = 1;

    while(size < n)
        size *= 2;

    Matrix P(size, vector<long long>(size, 0));
    Matrix Q(size, vector<long long>(size, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            P[i][j] = A[i][j];
            Q[i][j] = B[i][j];
        }

    Matrix R = Strassen(P, Q);

    cout << "Product matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << R[i][j] << " ";

        cout << endl;
    }

    return 0;
}