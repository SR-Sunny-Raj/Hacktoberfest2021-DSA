public class Kthelement {
    public static void main(String[] args) {
        int arr1[] = {6, 13, 16, 17, 19};
        int arr2[] = {11, 14, 18, 20};
        int k = 5;
        System.out.print(kthelement(arr1, arr2, 5, 4, k));
    }
    static int kthelement(int arr1[], int arr2[], int m, int n, int k)
    {
        int[] sorted1 = new int[m + n];
        int i = 0, j = 0, d = 0;
        while (i < m && j < n)
        {
            if (arr1[i] < arr2[j])
                sorted1[d++] = arr1[i++];
            else
                sorted1[d++] = arr2[j++];
        }
        while (i < m)
            sorted1[d++] = arr1[i++];
        while (j < n)
            sorted1[d++] = arr2[j++];
        return sorted1[k - 1];
    }
}
