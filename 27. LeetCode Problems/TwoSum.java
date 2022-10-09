// Java Program To Implement Two Sum Problem
import java.util.*;

public class TwoSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter No. Of Elements: ");
        int n = sc.nextInt();
        System.out.println("Enter Target Value: ");
        int target = sc.nextInt();
        int[] arr = new int[n];
        
        for(int i = 0; i < n; i++) {
            System.out.println("Enter Element" + i + ": ");
            int tmp = sc.nextInt();
            arr[i] = tmp;
        }
        int[] result = twoSum(arr, target);
        System.out.println(result[0] + " " + result[1]);
        sc.close();
    }

    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                result[0] = map.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            map.put(nums[i], i);
        }
        return result;
    }
}

