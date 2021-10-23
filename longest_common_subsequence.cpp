// LCS
                       /*

                         lcs("AXYT", "AYZX")
                       /                 \
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                 \             /               \
lcs("AX", "AYZX")  lcs("AXY", "AYZ")   lcs("AXY", "AYZ")  lcs("AXYT", "AY") 
 */

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);  
  
int lcs( char *X, char *Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n];  
}   
    
// Driver code */
int main()  
{  
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
      
    int m = strlen(X);  
    int n = strlen(Y);  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
      
    return 0;  
}  
  