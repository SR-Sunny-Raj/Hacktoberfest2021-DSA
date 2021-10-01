//Radix Sort

#include <iostream> 
using namespace std; 
  int c=0;

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++,c++) 
        if (arr[i] > mx) { c++;
            mx = arr[i];  }
    return mx; 
} 
  

void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = { 0 }; 
  
    
    for (i = 0; i < n; i++,c++) 
        count[(arr[i] / exp) % 10]++; 
  
   
    for (i = 1; i < 10; i++,c++) 
        count[i] += count[i - 1]; 
  
 
    for (i = n - 1; i >= 0; i--,c++) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    for (i = 0; i < n; i++,c++) 
        arr[i] = output[i]; 
} 
  


void radixsort(int arr[], int n) 
{ 

    int m = getMax(arr, n); 
  
   
    for (int exp = 1; m / exp > 0; exp *= 10,c++) 
        countSort(arr, n, exp); 
} 
  

void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i,c++) 
        cout << arr[i] << " "; 
} 
  

int main() 
{ 
    int arr[100];
    int n;
    cout << "input array size n"<<endl;
    cin >> n;
    for(int j=0;j<n;j++,c++)
    {
        cin >> arr[j];
    }
      radixsort(arr, n); 
    print(arr, n); 
     cout << "Step count:" << c / n << "n+ " << c % n << "\n";
         if (c >= n * n)
    {
        cout << c / (n * n) << "n^2+ ";
        c = c % (n * n);
    }
    cout << c / n << "n+ " << c % n << "\n";
    return 0; 
}
