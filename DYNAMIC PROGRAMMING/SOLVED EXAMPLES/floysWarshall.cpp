#include<iostream>
#include<string.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int adjMat[n][n];
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
        string num;
        cin>>num;
        if(num=="INF")
            adjMat[i][j]=99999;
        else
            adjMat[i][j]=stoi(num);
    }
    
    int A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                A[i][j] = adjMat[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 99999)
                cout<<"INF ";
            else
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}