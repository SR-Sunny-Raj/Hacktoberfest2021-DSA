#include <iostream>
using namespace std;
 

void gnomesort(int arr[], int n)
{
    int a = 0;
 
    while (a < n) {
        if (a == 0)
            a++;
        if (arr[a] >= arr[a - 1])
            a++;
        else {
            swap(arr[a], arr[a - 1]);
            a--;
        }
    }
    return;
}
 

void printArray(int arr[], int n)
{
    cout << "Sorted sequence after Gnome sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
 

int main()
{
    int arr[] = { 55,88,22,31,14,11,25 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    gnomesort(arr, n);
    printArray(arr, n);
 
    return (0);
}
