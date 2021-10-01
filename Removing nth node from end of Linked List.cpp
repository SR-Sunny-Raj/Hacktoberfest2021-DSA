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
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* f = head;
        ListNode* s = head;
        
        for(int i=0;i<n;i++){
            f = f->next;
        }
        
        if(f==NULL){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        
        while(f->next!=NULL){
            f = f->next;
            s = s->next;
        }
        
        ListNode* p = s;
        s = s->next;
        ListNode* k = s->next;
        p->next = k;
        
        delete s;
        
        
        return head;
        
    }
};