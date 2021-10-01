//program to insert and delete an element of array

#include<iostream>
using namespace std;

class arrayadt
{
    int capacity;
    int lastindex;
    int* ptr;
    public:
    
    arrayadt()
    {
        capacity=0;
        lastindex=-1;
        ptr=NULL;
    }
    
    void capacityl(int);
    void setvalue(int,int);
    void insertvalue(int,int);
    void removeelement(int);
    void print();

};

void arrayadt::capacityl(int capacity)
{
    this->capacity=capacity;
    lastindex=-1;
    ptr=new int[capacity];
}

void arrayadt::setvalue(int i,int v)
{
    if(i<0||i>capacity)
    {
        cout<<"invalid input";
    }
    
    else if(i<capacity&&i>=0)
    {
        ptr[i]=v;
        lastindex++;
    }
}

void arrayadt::insertvalue(int in,int va)
{
   int nl;
   if(in<0||in>capacity)
    {
        cout<<"invalid input";
    }
     if(in<capacity&&in>0)
    {
       lastindex++;
       nl=lastindex;
       while(nl!=in)
       {
        ptr[nl]=ptr[nl-1];
        nl--;
       }
        ptr[nl]=va;
    }
}

void arrayadt::removeelement(int ind)
{
    if(ind<0||ind>capacity-1)
    {
        cout<<"invalid index";
    }
    
    else if(ind<lastindex&&ind>0)
    {
        while(ind!=lastindex)
        {
            ptr[ind]=ptr[ind+1];
            ind++;
        }
        lastindex--;
    }
}
void arrayadt::print()
{
    for(int i=0;i<=lastindex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}


int main()
{
    arrayadt o1;
    o1.capacityl(7);
    o1.setvalue(0,10);
    o1.setvalue(1,20);
    o1.setvalue(2,30);
    o1.setvalue(3,50);
    cout<<"array before insertion :";
    o1.print();
    cout<<"\narray after insertion :";
    o1.insertvalue(3,40);
    o1.print();
    cout<<"\narray after removing value :";
    o1.removeelement(1);
    o1.print();
return 0;
}
