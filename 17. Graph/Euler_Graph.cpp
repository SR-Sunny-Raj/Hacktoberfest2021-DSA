#include <iostream>
using namespace std;
int main()
{
 bool flag=false;
 int n,count=0;
  cout << " Enter the no. of vertices " << endl;
 cin>>n;
 int ar[n][n];
 cout<<"Enter ur vale in  1 & 0 :"<<endl;
 for(int i=0;i<n;i++)
 { int sum=0;
 for(int j=0;j<n;j++)
 { 
 cin>>ar[i][j];
 if(ar[i][j]%2!=0)
 {
 flag=true;
 count++;
 }
 
 
 }
 
 }
 
 if(count==2)
 cout<<"Euler path\n";
 else if(flag)
 {
 cout<<"Neither Euler circuit nor Euler path\n";
 }
 else
 cout<<"Euler circuit\n";
}
