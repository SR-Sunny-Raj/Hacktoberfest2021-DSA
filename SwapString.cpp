#include<iostream>
using namespace std;

int main()
{
  int i=0, j=0, k=0;
  char str1[20], str2[20], temp[20];

  cout<<"\nEnter the First String :: ";
  gets(str1);

  cout<<"\nEnter the Second String :: ";
  gets(str2);

  cout<<"\nStrings before swapping are ::\n";
  cout<<"\n\tString 1 = "<<str1<<"\n";
  cout<<"\n\tString 2 = "<<str2<<"\n";
  while(str1[i]!='\0')
  {
        temp[j]=str1[i];
        i++;
        j++;
  }
  temp[j]='\0';
  i=0, j=0;
  while(str2[i]!='\0')
  {
        str1[j]=str2[i];
        i++;
        j++;
  }
  str1[j]='\0';
  i=0, j=0;
  while(temp[i]!='\0')
  {
        str2[j]=temp[i];
        i++;
        j++;
  }
  str2[j]='\0';
  cout<<"\nStrings after swapping :: \n";
  cout<<"\n\tString 1 = "<<str1<<"\n";
  cout<<"\n\tString 2 = "<<str2<<"\n";

  return 0;
}
