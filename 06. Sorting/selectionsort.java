import java.util.Scanner;

class selectionsort{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
        arr[i]=sc.nextInt();
        for (int x = 0; x < n-1; x++)
        {
            int min = x;
            for (int y = x+1; y < n; y++)
                if (arr[y] < arr[min])
                    min = y;

            int t = arr[min];
            arr[min] = arr[x];
            arr[x] = t;
        }
        for(int i=0;i<n;i++)
        System.out.println(arr[i]);
    }
}