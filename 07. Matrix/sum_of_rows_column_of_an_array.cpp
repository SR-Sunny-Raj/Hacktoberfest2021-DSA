/*program to find sum of every row and every column in a two-dimensional
array.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,s=0,k=0;
    cin>>m>>n;
    int a[m][n];
    int b[m+n];
    for(i=0;i<m;i++)
    {
        s=0;
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            s+=a[i][j];
        }
        b[k++]=s;
    }
    for(i=0;i<n;i++)
    {
        s=0;
        for(j=0;j<m;j++)
        {
            s+=a[j][i];
        }
        b[k++]=s;
    }
    for(i=0;i<m;i++)
    {
        cout<<"Sum of row "<<(i+1)<<" is "<<b[i]<<endl;
    }
    k=1;
    for(i;i<(m+n);i++)
    {
        cout<<"Sum of column "<<k++<<" is "<<b[i]<<endl;
    }
    return 0;
}