/*Problem Statement: Given the head of a linked list, rotate the list to the right by k places.
Example :
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]*/

/*Solution:*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
          // edge cases 
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len) 
            cur = cur->next;
        
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        
        return head; 
    }
};
