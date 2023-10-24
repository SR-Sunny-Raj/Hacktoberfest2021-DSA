// Problem Statement :- https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length ==0 || lists == null){
            return null;
        }
        
        int interval = 1;
        while(interval<lists.length){
            for(int i=0; i+interval<lists.length;i=i+interval*2){
                lists[i]=mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval = interval*2;
        }
        return lists[0];
    }
     public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null){
            return l2;
        }else if(l2 == null){
            return l1;
        }else if(l1.val<l2.val){
//here if l1.val<l2.val then we will call the function gor l1.next and l2
            l1.next = mergeTwoLists( l1.next,l2);
            return l1;
        } else {
// here if l1.val>l2.val then we will call the function gor l1 and l2.next
             l2.next = mergeTwoLists( l1,l2.next);
             return l2;
        }
    }
}