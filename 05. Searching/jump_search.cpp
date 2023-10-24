#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100
int search(int key);
int a[MAX],n;
int main()
{
   int i,key,result;
   cout<<"\nEnter the number of elements: ";
   cin>>n;
   cout<<"\nEnter the elements of array: \n";
   for(i=0;i<n;i++)
   {
         cin>>a[i];
   }
      cout<<"\n\nEnter the key you want to search: ";
      cin>>key;
      result=search(key);
      if(result==-1)
      {
            cout<<"\nElement is not found in the array !\n";
      }
      else
      {
            cout<<"\nElement "<<key<<" is present at position "<<result;
      }
      return 0;
}
int search(int key)
{
   int jump_step,prev=0;
   jump_step=floor(sqrt(n));

   while(a[prev]<key)
   {
       if(a[jump_step]>key || jump_step>=n)
       {
            break;
       }
       else
       {
                prev=jump_step;
                jump_step=jump_step+floor(sqrt(n));
       }
   }

   while(a[prev]<key)
   {
        prev++;
   }
   if(a[prev]==key)
   {
        return prev+1;
   }
   else
   {
        return -1;
   }
}
