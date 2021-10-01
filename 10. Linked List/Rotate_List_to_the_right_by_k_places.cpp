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
        ListNode* prev=head; ListNode* curr=head;
        ListNode* temp;
        int c=count(head);
        
        if(head==NULL||k==0||head->next==NULL)
            return head;
        
        if (c==k) return head;
        else if(c<k) k=k%c;
        c=c-k;
        
        while(prev->next!=NULL)
        {
            if(c>1)
            {
                curr=curr->next; 
                c--;
            }
            prev=prev->next;           
        }
        
        prev->next=head;        
        head=curr->next;
        curr->next=NULL;
        
        return head;
        
    }
    
    int count(ListNode* head)
    {
            if(head==NULL)
                return 0;
            else return 1+count(head->next);
        }
};
