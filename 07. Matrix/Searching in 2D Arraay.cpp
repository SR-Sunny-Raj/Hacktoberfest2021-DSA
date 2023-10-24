 #include <iostream>
using namespace std;

int main() 
{
        int n,m,k;
        cin >>n>>m>>k;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
            }
        }
        int r=0,q=m-1;
           while(r<n&&q>=0)
           {
               if(a[r][q]==k)
               cout << "FOUND";
               else if(a[r][q]>k)
               q--;
               else
               r++;
           }
           
	return 0;
}
