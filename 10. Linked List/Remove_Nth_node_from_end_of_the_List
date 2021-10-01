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
        ListNode* curr=head;
        if(head==NULL)
            return head;
        if(head->next==NULL)
        {
            head=NULL;
            return head;
        }
            
        int c= count(head);
        if(c==n)
        {
            head=head->next;
            return head;
        }
        c=c-n;
        
        while(curr->next!=NULL && --c)
        {
            curr=curr->next; 
        }
        curr->next=curr->next->next;
        return head;
        
    }
    int count(ListNode* head)
    {
        if(head==NULL)
            return 0;
        else return 1+count(head->next);
    }
};
