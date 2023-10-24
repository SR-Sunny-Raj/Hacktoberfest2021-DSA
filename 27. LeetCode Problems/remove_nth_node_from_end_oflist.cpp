// Given the head of a linked list, 
// remove the nth node from the end of the list and return its head.

class Solution {
public:
    struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next=head;
    struct ListNode* s=p;
    struct ListNode* f=p;
    for(int i=1; i<=n; i++)
        f=f->next;
     while(f->next!=NULL)
    {
        s=s->next;
        f=f->next;
    }
    s->next=s->next->next;
    return p->next;
}
};