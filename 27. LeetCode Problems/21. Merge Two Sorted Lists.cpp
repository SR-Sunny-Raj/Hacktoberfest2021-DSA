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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
        while(c1 != NULL && c2 != NULL) {
            if(c1->val < c2->val) {
                prev->next = c1;
                c1 = c1->next;
            }
            else {
                prev->next = c2;
                c2 = c2->next;
            }
            prev = prev->next;
        }
        
        prev->next = c1 == NULL ? c2 : c1;
        return dummy->next;
    }
};