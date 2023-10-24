// Problem description
// Find the unique elements present in an array
//sample input : 1 3 9 2 2 1 15 7 8
//sapmle output : 1 2 3 9 15 7 8


#include <iostream>
using namespace std;
 
 int main()
 
 {
     int size;
     cout<<"Enter size of array";
     cin>>size;
     int arr[size-1];
     cout<<"Enter elements of array";
                                    //taking input of an array
     for(int i=0;i<size;i++){
         cin>>arr[i];

     }
                                    //printing the original array
     cout<<"Original array"<<" : ";
     for(int i=0;i<size;i++){
         cout<<arr[i]<<" ";

     }
     cout<<"Unique elements are :";
     for (int i=0; i<size; i++)
    {
        int j;
        for (j=0; j<i; j++)         //checking if the element reoccurs if yes then break of for loop
                                            
           if (arr[i] == arr[j])
               break;
         if (i == j)                //printing of Unique elements
            cout << arr[i] << " ";
    }




 }