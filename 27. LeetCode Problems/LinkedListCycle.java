// Problem Statement :- https://leetcode.com/problems/linked-list-cycle/

public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null) return false;
        ListNode precidence = head;
        ListNode temp = head.next;
        
        while(precidence != temp){
             if(temp==null || temp.next == null){
            return false;
        }
            precidence = precidence.next;
            temp = temp.next.next;
        }
       
        return true;
    }
}