package Stack;

import java.util.Stack;

public class lexoKsubseq {

//Q) You are given an array of integers arr, and an integer k. You have to output the lexographically smallest 
//subsequence of arr of length 'k'

    public static void lexoSubseqK(int[] arr, int k){

        int[] ans= new int[k];
        Stack<Integer> st= new Stack<>();

        for(int i=0; i<arr.length; i++){

            
                while( (!st.isEmpty()) && st.peek()> arr[i] && arr.length-i-1>= k-st.size() )
                st.pop();


                if(st.isEmpty() || st.size()<k)
                st.push(arr[i]);
	}

        int idx=k-1;


        while(!st.isEmpty()){
            ans[idx--]=st.pop();
        }

        for(int x: ans){
            System.out.print(x+" ");
        }


    }


    public static void main(String[] args) {

        int[] arr= {3,1,5,2,5,9,4};
        int k=4;
        lexoSubseqK(arr, k);
    }
    
}
