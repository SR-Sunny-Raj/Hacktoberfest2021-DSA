#include<stdio.h>
#include<stdlib.h>
#define size 100
int count = 10,n=0;
int a[99];
void printtree(int i,int space)
{
  if(i>n)
  {
    return;
  }
  space+=count;
  printtree(2*i+1,space);
  printf("\n");
  for(int i=count;i<space;i++)
  {
    printf(" ");
  }
  printf("%d\n",a[i]);
  printtree(2*i,space);
}
void swap(int i,int j)
{
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
void heapinsert()
{
  int i,p,item,temp;
  printf("ENTER THE ITEM TO INSERT: ");
  scanf("%d",&item);
  if(n>size)
  {
    printf("INSERION NOT POSSIBLE\n");
  }
  else
  {
    n++;
    a[n]=item;
    i = n;
    p = i/2;
    while(p>0 && a[p]<a[i])
    {
      temp = a[i];
      a[i] = a[p];
      a[p] = item;
      i = p;
      p = i/2;
    }
  }
}
void heapdelete()
{
  int item,flag,i,lc,rc,largest;
  int x = -100000,y=-100000;
  if(n==0)
  {
    printf("DELETION NOT POSSIBLE\n");
  }
  else
  {
    item = a[1];
    a[1] = a[n];
    n--;
    flag=0;
    i=1;
    while(flag==0 && i<n)
    {
      lc = 2*i;
      rc = 2*i + 1;
      if(a[lc]>a[rc] && a[lc]>a[i])
      {
        largest=lc;
      }
      else if(a[lc]<a[rc] && a[rc]>a[i])
      {
        largest=rc;
      }
      else
      {
        flag=1;
      }
      if(flag==0)
      {
        swap(largest,i);
        i=largest;
      }
    }
  }
  printf("DELETED ELEMENT: %d\n",item);
}
void heapsort()
{
  int j,i=n;
  while(i>1)
  {
    if(a[1]>a[i])
    {
      swap(1,i);
    }
    i--;
    j=1;
    while (j<i)
    {
      int lc = 2*j;
      int rc = 2*j + 1;
      if(lc<i)
      {
        if(rc<i)
        {
          if(a[j]<a[lc] && a[lc]>a[rc])
          {
            swap(j,lc);
            j=lc;
          }
          else if(a[j]<a[rc] && a[lc]<a[rc])
          {
            swap(j,rc);
            j=rc;
          }
          else
          {
            break;
          }
        }
        else
        {
          if(a[lc]>a[j])
          {
            swap(j,lc);
            j=lc;
          }
          else
          {
            break;
          }
        }
      }
      else
      {
        break;
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    printf("%d\t",a[i]);
  }
}
void main()
{
  int ch;
  do
  {
    printf("\n\t\tMENU\n");
    printf("1.INSERTION  2.DELETION  3.SORTING 4.DISPLAY  5.EXIT\n");
    printf("ENTER THE CHOICE: ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1 : heapinsert();
               break;
      case 2 : heapdelete();
               break;
      case 3 : heapsort();
               break;
      case 4 : printf("\n\n");
               printtree(1,0);
               break;
      case 5 : printf("EXITING...........\n");
               exit(0);
      default : printf("INVALID ENTRY!!!\n");
    }
  } while(ch);
}
