#include <iostream>
using namespace std;

void spiralPrint(int a[][1000], int m, int n){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/

    int i, k = 0, l = 0; 
  
    /* k - starting row index  
        m - ending row index  
        l - starting column index  
        n - ending column index  
        i - iterator  
    */
  
    while (k < m && l < n) { 
        /* Print the first row from 
               the remaining rows */
        for (i = l; i < n; ++i) { 
            cout << a[k][i] << " "; 
        } 
        k++; 
  
        /* Print the last column  
         from the remaining columns */
        for (i = k; i < m; ++i) { 
            cout << a[i][n - 1] << " "; 
        } 
        n--; 
  
        /* Print the last row from  
                the remaining rows */
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                cout << a[m - 1][i] << " "; 
            } 
            m--; 
        } 
  
        /* Print the first column from 
                   the remaining columns */
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                cout << a[i][l] << " "; 
            } 
            l++; 
        } 
    } 
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}
