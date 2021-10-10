
#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{

	int m,n;
	cout<<"enter m then n";
	cin>>m>>n;
	int a[2*m + 1];
	int b[2*n + 1];
	int c[2*m*n + 1];
	for(int i=0;i<=2*m*n;i++)
		c[i] = 0;
	int r=1;
	cout<<"enter a";
	for(int i=0;i<=2*m;i++)
	    cin>>a[i];
	cout<<"enter b";
	for(int i=0;i<=2*n;i++)
	    cin>>b[i];
	for(int p = 1; p<= 2*m ; p=p+2)
	{
		for(int q = 1;q <= 2*n; q = q+ 2)
		{
			c[r] = a[p] + b[q];
			c[r+1] = a[p+1]*b[q+1];
			r = r+2;

		}
	}
	for(int i=1;i<=2*m*n;i=i+2)
	{
		for(int j=1;j<=2*m*n;j=j+2)
		{
			if(c[i]==c[j] && j!= i)
			{
				c[i+1] = c[i+1] + c[j+1];
				c[j] =0;
				c[j+1] =0;


			}
		}
	}
	int nonzero = 0;
	for(int i=1;i<=2*m*n;i=i+2)
	{
		if(c[i+1] != 0)
			nonzero++;
	}
	c[0] = nonzero;
	for(int i=0;i<=2*m*n;i++)
	{

        if(i!= 2*m*n && c[i]==0 & c[i+1] == 0)
        {
            i++;
            continue;
        }
        cout<< " "<<c[i];
	}

	return 0;
}

