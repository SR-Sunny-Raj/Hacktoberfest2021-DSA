
import java.util.*;
public class StackUsingQueue{


    public static class StackUsingQueues_harpreet1602{
        LinkedList<Integer> q1 = new LinkedList<>();
        LinkedList<Integer> q2 = new LinkedList<>();
        
        
        
        public StackUsingQueues_harpreet1602(){
    
        }
        public void swap(LinkedList<Integer> first, LinkedList<Integer> second){
            while(first.size()!=1){
                second.addLast(first.removeFirst());
            }
        }
        public void swap2(LinkedList<Integer> first, LinkedList<Integer> second){
            while(first.size()!=0){
               second.addLast(first.removeFirst()); 
            }
        }
        public void push(int x) {
            q1.addLast(x);
        }
        
        public int pop() {
            swap(q1,q2);
            int val = q1.removeFirst();    
            swap2(q2,q1);
            return val;
        }
        
        public int top() {
        swap(q1,q2);
        int val = q1.getFirst(); 
        q2.addLast(q1.removeFirst());
        swap2(q2,q1);  
        return val;
        }
        
        public boolean empty() {
            return q1.size()==0;
        }
    
        
    }
    public static void main(String[] args){
        StackUsingQueues_harpreet1602 st =new StackUsingQueues_harpreet1602();
        st.push(10);
        st.push(20);
        st.push(30);
        System.out.println(st.pop());
        System.out.println(st.top());
    }

}