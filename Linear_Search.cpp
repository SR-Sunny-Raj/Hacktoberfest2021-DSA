C++ Program to implement Linear Search using Arrays
Linear Search using Arrays
What is an Array ?
Arrays a kind of data structure that can store a fixed-size sequential collection of elements of the same type. An array is used to store a collection of data, but it is often more useful to think of an array as a collection of variables of the same type.


 

 
Instead of declaring individual variables, such as number0, number1, …, and number99, you declare one array variable such as numbers and use numbers[0], numbers[1], and …, numbers[99] to represent individual variables. A specific element in an array is accessed by an index.

All arrays consist of contiguous memory locations. The lowest address corresponds to the first element and the highest address to the last element.

Here is source code of the C++ Program to implement Linear Search using Arrays. The C++ program is successfully compiled and run(on Codeblocks) on a Windows system. The program output is also shown in below.


 
SOURCE CODE : :
/*  C++ Program to implement Linear Search using Arrays  */

#include<iostream>

using namespace std;

int main()
{
    int a[20],n,x,i,flag=0;

    cout<<"Enter size of Array :: ";
    cin>>n;
    cout<<"\nEnter elements to the array :: \n";

    for(i=0;i<n;++i)
    {
        cout<<"\nEnter "<<i+1<<" element :: ";
        cin>>a[i];
    }


    cout<<"\nEnter element to search :: ";
    cin>>x;

    for(i=0;i<n;++i)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }

    if(flag)
        cout<<"\nElement is found at position "<<i+1;
    else
        cout<<"\nElement not found";

    return 0;
}
OUTPUT : :
/*  C++ Program to implement Linear Search using Arrays  */

Enter size of Array :: 7

Enter elements to the array ::

Enter 1 element :: 1

Enter 2 element :: 2

Enter 3 element :: 3

Enter 4 element :: 4

Enter 5 element :: 5

Enter 6 element :: 6

Enter 7 element :: 7

Enter element to search :: 4

Element is found at position 4

Process returned 0
