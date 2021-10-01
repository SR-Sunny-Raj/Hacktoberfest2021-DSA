// This program takes input as n which is number of queens to be put.
// For problem statement follow below link
// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

#include<iostream>
using namespace std;

bool isSafeToPut(int sol[][10],int i,int j,int n)
{
	for(int k=0;k<n;k++)
	{
		if(sol[k][j] || sol[i][k])
		{
			return false;
		}
	}

	int row=i,col=j;
	while(row>=0 && col>=0)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col--;
	}

	row=i,col=j;

	while(row>=0 && col<n)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col++;
	}

	return true;

}


bool nqueen(int sol[][10],int i,int n)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	for(int j=0;j<n;j++)
	{
		if(isSafeToPut(sol,i,j,n))
		{
			sol[i][j]=1;
			bool kyaAageRakhPaye=nqueen(sol,i+1,n);
			if(kyaAageRakhPaye)
			{
				return true;
			}
			sol[i][j]=0;
		}
	}

	return false;

}


int main()
{
	int sol[10][10]={0};
	int n;
	cin>>n;
	nqueen(sol,0,n);
	return 0;
}