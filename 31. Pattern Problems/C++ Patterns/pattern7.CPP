#include<iostream.h>
#include<conio.h>
void condition(int i,int j,int n)
{ int k=0;
  if(i>4)
  {
   k=i-4;
   if(k+j<5) cout<<n<<" ";
   else cout<<"  ";
  }
  else
  {k=i;
   if(k==j||k>j) cout<<n<<" ";
   else cout<<"  ";
  }
}
void main()
{
clrscr();
int i=0,j=0,n=0,m=0;
for(i=0,m=5;i<9;i++)
{
 for(j=0;j<4;j++)
 {n=5-j;
  condition(i,j,n);
 }
 n=m;
 for(j=0;j<5;j++)
 {
  condition(i,j,n);
  n++;
 }
 if(i<4) m--;
 else m++;
cout<<'\n';
}
getch();
}