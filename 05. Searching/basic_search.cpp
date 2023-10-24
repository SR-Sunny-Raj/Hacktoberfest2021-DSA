#include <iostream>
#include <algorithm>

using namespace std;
int linearSearch(int arr[], int n, int x){
      for(int i=0;i<n;i++){
          if(arr[i]==x)
            return i;
      }
      return -1;
}
int main()
{
    int n,key,i;
    cout<<"Enter size of array):"<<endl;
    cin>>n;
    int arr[n];
    cout << "Please enter "<<n<<" numbers (with spaces between them): ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter number for searching: ";
    cin >> key;
    
    int index = linearSearch(arr,n, key);

    if (index != -1) {
       cout<<"Element found at index "<<index;
    } else {
        cout<<"Element not found in the array";
    }
    return 0;
}