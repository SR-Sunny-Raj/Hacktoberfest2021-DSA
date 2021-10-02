#include<iostream>
using namespace std;

int **createMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

int** addTwoMatrices(int** A, int **B, int n)
{
    int** result = createMatrix(n,n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subTwoMatrices(int** A, int** B, int n)
{
    int** result = createMatrix(n,n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int** MM(int **A, int **B, int n)
{
    int **C = createMatrix(n,n);
    if (n<=2)
    {
        n--;
        int P = (A[n/2][n/2]+A[n][n])*(B[n/2][n/2]+B[n][n]);
        int Q = (A[n][n/2]+A[n][n])*B[n/2][n/2];
        int R = A[n/2][n/2]*(B[n/2][n]-B[n][n]);
        int S = A[n][n]*(B[n][n/2]-B[n/2][n/2]);
        int T = (A[n/2][n/2]+A[n/2][n])*B[n][n];
        int U = (A[n][n/2]-A[n/2][n/2])*(B[n/2][n/2]+B[n/2][n]);
        int V = (A[n/2][n]-A[n][n])*(B[n][n/2]+B[n][n]);

        C[n/2][n/2] = P + S - T + V;
        C[n/2][n] = R + T;
        C[n][n/2] = Q + S;
        C[n][n] = P + R - Q + U;

        return C;
    }
    int** a11 = createMatrix(n/2,n/2);
    int** a12 = createMatrix(n/2,n/2);
    int** a21 = createMatrix(n/2,n/2);
    int** a22 = createMatrix(n/2,n/2);
    int** b11 = createMatrix(n/2,n/2);
    int** b12 = createMatrix(n/2,n/2);
    int** b21 = createMatrix(n/2,n/2);
    int** b22 = createMatrix(n/2,n/2);

    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j+n/2];
            a21[i][j] = A[i+n/2][j];
            a22[i][j] = A[i+n/2][j+n/2];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j+n/2];
            b21[i][j] = B[i+n/2][j];
            b22[i][j] = B[i+n/2][j+n/2];
        }
    }

    int **p, **q, **r, **s, **t, **u, **v;

    p = MM(addTwoMatrices(a11,a22,n/2),addTwoMatrices(b11,b22,n/2),n/2);
    q = MM(addTwoMatrices(a21,a22,n/2),b11,n/2);
    r = MM(a11,subTwoMatrices(b12,b22,n/2),n/2);
    s = MM(a22,subTwoMatrices(b21,b11,n/2),n/2);
    t = MM(addTwoMatrices(a11,a12,n/2),b22,n/2);
    u = MM(subTwoMatrices(a21,a11,n/2),addTwoMatrices(b11,b12,n/2),n/2);
    v = MM(subTwoMatrices(a12,a22,n/2),addTwoMatrices(b21,b22,n/2),n/2);

    int** c11, **c12, **c21, **c22;
    c11 = addTwoMatrices(subTwoMatrices(addTwoMatrices(p,s,n/2),t,n/2),v,n/2);
    c12 = addTwoMatrices(r,t,n/2);
    c21 = addTwoMatrices(q,s,n/2);
    c22 = addTwoMatrices(subTwoMatrices(addTwoMatrices(p,r,n/2),q,n/2),u,n/2);

    
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = c11[i][j];
            C[i][j + n/2] = c12[i][j];
            C[i + n/2][j] = c21[i][j];
            C[i + n/2][j + n/2] = c22[i][j];
        }
    }

    
    return C;
}

int main()
{
    int n;
    cin>>n;
    int** A = createMatrix(n,n);
    int** B = createMatrix(n,n);
    int** C;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }

    cout<<endl;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>B[i][j];
        }
    }

    C = MM(A,B,n);
    
    cout<<"Answer: "<<endl<<endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<C[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}