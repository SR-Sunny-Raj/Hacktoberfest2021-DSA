public class BitonicSort
{
    /* The parameter dir indicates the sorting direction,
       ASCENDING or DESCENDING; if (a[i] > a[j]) agrees
       with the direction, then a[i] and a[j] are
       interchanged. */
    void compAndSwap(int a[], int i, int j, int dir)
    {
        if ( (a[i] > a[j] && dir == 1) ||
             (a[i] < a[j] && dir == 0))
        {
            // Swapping elements
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
 
    void bitonicMerge(int a[], int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;
            for (int i=low; i<low+k; i++)
                compAndSwap(a,i, i+k, dir);
            bitonicMerge(a,low, k, dir);
            bitonicMerge(a,low+k, k, dir);
        }
    }
 
    void bitonicSort(int a[], int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;
 
            // sort in ascending order since dir here is 1
            bitonicSort(a, low, k, 1);
 
            // sort in descending order since dir here is 0
            bitonicSort(a,low+k, k, 0);
 
            // Will merge whole sequence in ascending order
            // since dir=1.
            bitonicMerge(a, low, cnt, dir);
        }
    }
 
    void sort(int a[], int N, int up)
    {
        bitonicSort(a, 0, N, up);
    }
 
    /* A utility function to print array of size n */
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
 
    public static void main(String args[])
    {
        int a[] = {3, 7, 4, 8, 6, 2, 1, 5};
        int up = 1;
        BitonicSort ob = new BitonicSort();
        ob.sort(a, a.length,up);
        System.out.println("\nSorted array");
        printArray(a);
    }
}
