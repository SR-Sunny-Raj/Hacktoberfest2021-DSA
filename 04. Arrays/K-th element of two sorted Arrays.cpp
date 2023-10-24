// Problem link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


//Solution:

 int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int arr3[n+m];

        for(int i=0; i<n; i++)
            arr3[i]=arr1[i];
            
        for(int j=0; j<m; j++)
            arr3[n+j]=arr2[j];
            
        sort(arr3, arr3+n+m);
        
        return arr3[k-1];
    }
