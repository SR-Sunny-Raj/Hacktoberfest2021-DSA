#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

void printMatrix(int arr[SIZE][SIZE], int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sortedMatrix(int arr[SIZE][SIZE], int n){

    int k=0;
    int temp[n*n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[k++]=arr[i][j];
        }
    }

    sort(temp, temp+(n*n));
    int l=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=temp[l++];
        }
    }
}

int maxRectangle(int arr[SIZE][SIZE]){

    int temp[sizeof(arr[0])] ;

    
}

int main()
{
    int arr[SIZE][SIZE] = { {1,1,1,0},
                            {1,1,1,1},
                            {0,1,1,0},
                            {0,1,1,1},
                            {1,0,0,1},
                            {1,1,1,1} };

        cout<<" Max Rectangle : "<<maxRectangle(arr);;
        
    
    return 0;
}
