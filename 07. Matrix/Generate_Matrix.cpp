/*
Given a matrix B[][] of dimensions N * M, the task is to generate a matrix A[][] of same dimensions that can be formed such that for any element B[i][j] is equal to Bitwise OR of all elements in the ith row and jth column of A[][]. If no such matrix exists, print “Not Possible“. Otherwise, print the matrix A[][].

Examples:

Input: B[][] = {{1, 1, 1},  {1, 1, 1}}
Output:
1 1 1
1 1 1
Explanation:
B[0][0] = 1 = bitwise OR of all elements in 0th row and 0th column of A[][].
B[0][1] = 1 = bitwise OR of all elements in 0th row and 1th column of A[][].
B[0][2] = 1 = bitwise OR of all elements in 0th row and 2th column of A[][].
B[1][0] = 1 = bitwise OR of all elements in 1th row and 0th column of A[][].
B[1][1] = 1 = bitwise OR of all elements in 1th row and 1th column of A[][].
B[1][2] = 1 = bitwise OR of all elements in 1th row and 2th column of A[][]. 

Input: B[][] = {{1, 0, 0}, {0, 0, 0}}
Output: Not Possible
*/

Solution:

#include <bits/stdc++.h>
using namespace std;
 
// Function to find the matrix, A[][]
// satisfying the given conditions
void findOriginalMatrix(
    vector<vector<int> > B, int N, int M)
{
    // Store the final matrix
    int A[N][M];
 
    // Initialize all the elements of
    // the matrix A with 1
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = 1;
        }
    }
 
    // Traverse the matrix B[][] row-wise
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
 
            // If B[i][j] is equal to 0
            if (B[i][j] == 0) {
 
                // Mark all the elements of
                // ith row of A[][] as 0
                for (int k = 0; k < M; ++k) {
                    A[i][k] = 0;
                }
 
                // Mark all the elements of
                // jth column of A[][] as 0
                for (int k = 0; k < N; ++k) {
                    A[k][j] = 0;
                }
            }
        }
    }
 
    // Check if the matrix B[][] can
    // be made using matrix A[][]
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
 
            // Store the bitwise OR of
            // all elements of A[][] in
            // ith row and jth column
            int c = 0;
 
            // Traverse through ith row
            for (int k = 0; k < M; ++k) {
                if (c == 1)
                    break;
                c += A[i][k];
            }
 
            // Traverse through jth column
            for (int k = 0; k < N; ++k) {
                if (c == 1)
                    break;
                c += A[k][j];
            }
 
            // If B[i][j] is not equal to
            // c, print "Not Possible"
            if (c != B[i][j]) {
                cout << "Not Possible";
                return;
            }
        }
    }
 
    // Print the final matrix A[][]
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    vector<vector<int> > B{ { 1, 1, 1 }, { 1, 1, 1 } };
 
    int N = B.size();
    int M = B[0].size();
 
    findOriginalMatrix(B, N, M);
 
    return 0;
}
