public class moveZeros {
    public static void printArray(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String args[]){
        int arr[] = {1, 2, 0, 0, 0, 3, 6};
        int n = arr.length;
        int out = 0;
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                arr[out] = arr[i];
                out++;
            }
        }
        for(int j = out; j<n; j++){
            arr[j] = 0;
        }
        printArray(arr);

    }
}
