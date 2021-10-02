/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* node=head;
        ListNode* prev=head;
        if(head == NULL ) return NULL;
        int c=1;
        while(node->next != NULL){
            c++;
            node=node->next;
        }
        node=head;
        
        int m=c-n;
        if(m == 0){
          if(node->next == NULL){
            head=NULL;
            
        }
        else{
            head=node->next;
        }  
             return head;
        }
        else{
        while(m >0){
            prev=node;
            node=node->next;
            m--;
        }
        if(node->next == NULL){
            prev->next=NULL;
        }
        else{
            prev->next=node->next;
        }
         return head;
        }  
    }
};