#include <iostream>
using namespace std;
void reverse(int arr[], int n){
    
    cout<<"Before reversing: ";
    for (int i = 0 ;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    int s = 0;
    int e = n-1;
    while (s<e){
        swap(arr[s],arr[e]);
        s+=1;
        e-=1;
    }
    cout<<"After reversing: ";
    for (int i = 0 ;i<n;i++){
        cout<<arr[i]<<" ,";
    }
}


int main(){
        int size;
  cout<<"Enter size of array: ";
  cin>>size;
  int arr[size];
  for (int i = 0;i<size;i++){
      cout<<"Enter "<<i+1<<" element of array: "; 
      cin>>arr[i];
  }
  int n = sizeof(arr) / sizeof(int);
  reverse(arr, n);
    return 0;;
    
}
