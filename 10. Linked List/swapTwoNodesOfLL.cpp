Node *swapNodes(Node *head, int i, int j)
{
    
    if(i>j){
        i=i+j;
        j=i-j;
        i=i-j;
    }

    if(i==0){
        if(j==1){
            Node *cur=head->next;
            head->next=cur->next;
            cur->next=head;
            return cur;
        }
        Node *pt=head;
        for(int c=1;c<j;c++)
            pt=pt->next;
        
    	Node *temp=head->next;
        Node *cur=pt->next;
        
        head->next=cur->next;
        pt->next=head;
        cur->next=temp;
        return cur;
        
    }
    if(j-i==1){
        Node * pt=head;
        for(int c=1;c<i;c++)
            pt=pt->next;
        
        Node* cur=pt->next;
        Node* cur1=cur->next;
        
        cur->next=cur1->next;
        pt->next=cur1;
        cur1->next=cur;
        return head;
        
    }
    Node *pt1=head;
    Node *pt2=head;
    
    for(int c=1;c<i;c++)
        pt1=pt1->next;
    
    for(int c=1;c<j;c++)
        pt2=pt2->next;
    
    Node *cur1=pt1->next;
    Node *cur2=pt2->next;
    
    Node *temp=cur1->next;
    
    cur1->next=cur2->next;
    pt2->next=cur1;
    pt1->next=cur2;
    cur2->next=temp;
    
    return head;
	
}
