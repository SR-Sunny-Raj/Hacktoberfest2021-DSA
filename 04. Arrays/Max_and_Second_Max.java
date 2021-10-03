//https://practice.geeksforgeeks.org/problems/max-and-second-max/1/?track=DSASP-Arrays
class ArrayMax{
    
    // Function to find largest and second largest element in the array
    public static ArrayList<Integer> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = -1;
        int secondMax = -1;
        
        for(int i = 0 ; i < sizeOfArray ; i++) {
            max = Math.max(max , arr[i]);
        }
        for(int i = 0 ; i < sizeOfArray ; i++) {
            if(arr[i] > secondMax && arr[i] < max ) {
                secondMax = arr[i];
            }
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        res.add(max);
        res.add(secondMax);
        return res;
    }
}