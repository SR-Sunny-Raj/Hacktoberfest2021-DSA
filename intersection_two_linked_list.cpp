ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    if(!headA && !headB)
      return nullptr;

    ListNode *a = headA;
    ListNode *b = headB;

    stack<ListNode*> s1;
    stack<ListNode*> s2;

    ListNode *temp = nullptr;

    while(a || b)
    {
        if(a)
        {
            s1.push(a);
            a = a->next;
        }

        if(b)
        {
            s2.push(b);
            b = b->next;
        }
    }

    while(!s1.empty() && !s2.empty())
    {
        if(s1.top() == s2.top())
        {
            temp = s1.top();
            s1.pop();
            s2.pop();
        }
        else
            break;

    }
    return temp;
}
