#include<iostream>

using namespace std;
struct node
{
    int marks;
    node *next;
}*NewNode, *res,*head,*temp, *prv,*nex, *current;
int count=0;

node* new_node(int m)
{
    NewNode = new node();
    NewNode->marks = m;
    NewNode->next = NULL;
    return NewNode;
}
void insert_beg(node *nexptr){
    if(head == NULL)
    {
        head = nexptr;
    }
    else
    {
        temp=head;
        head = nexptr;
        nexptr->next = temp;
        
    }
}
void insert_end(node *nexptr)
{
    if(head == NULL)
    {
        head = nexptr;
    }
    else
    {
        temp=head;

        while(temp !=NULL)
        {
            prv=temp;
            temp=temp->next;
        }
        prv->next=nexptr;
    }
}
void insert_at_position(node *nexptr, int pos)
{
    if(pos<1 || pos> count+1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos>count)
    {
        insert_end(res);
    }
    else
    {
        if(head==NULL)
        {
            head = nexptr; 
        }
        else
        {
            temp=head;
            for(int i=0;i<pos;i++)
            {
                prv=temp;
                temp=temp->next;
            }
            prv->next=nexptr;
            nexptr->next=temp;
        }
    }
}
void sorted_insert(node *nxtptr)
{
    if(head == NULL)
    {
        head= nxtptr;
    }
    else if(head->marks >= nxtptr->marks)
    {
        nxtptr->next = head;
        head= nxtptr;
    }
    else
    {
        current=head;
        while(current->next!=NULL) 
        {
            if(current->next->marks > nxtptr->marks)
            {
                break;
            }
            current = current->next;
        }
        nxtptr->next = current->next; 
        current->next = nxtptr;
    }
}
void delete_beg(node *hd)
{
    if(hd == NULL)
    {
        cout<<"Underflow "<<endl;
    }
    else
    {
     temp=hd;
     cout<<"node deleted "<<temp->marks<<endl;
     head = temp->next;
    }
}
void delete_end(node *hd)
{
    if(hd == NULL)
    {
        cout<<"Underflow "<<endl;
    }
    else
    {   temp=hd;
       if(temp->next == NULL)
       {
            cout<<"node deleted "<<temp->marks<<endl;
            head = NULL;
            cout<<"list is now empty "<<endl;
        }
        else
        {
            temp = hd;
            while(temp->next != NULL)
            {
                prv = temp;
                temp = temp->next;
            }
            cout<<"node deleted "<<temp->marks<<endl;
           prv->next=NULL;
        }
    }
    
}
void delete_at_position(node *hd, int pos)
{
    if(head == NULL)
    {
        cout<<"Underflow "<<endl;
    }
    else
    {
         temp=hd;
        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        nex = temp->next;
        temp->next=nex->next;
        cout<<"node deleted "<<nex;
            
    }
}

void Search(node *hd, int x)
{
    int p = 0;
    current = hd;
    while(current != NULL)
    {
        if(current->marks == x)
        {
            p=1;
            break;
        }
        current= current->next;
    }

    if(p==1)
    {
        cout<<x<<" Element Present"<<endl;
    }
    else
    {
        cout<<x<<" Element NOT Present"<<endl;
    }
}

void Result(node *nexptr)
{
    while(nexptr !=NULL)
    {
        cout<<nexptr->marks<<" stored at address "<<nexptr<<endl;
        nexptr=nexptr->next;
    }
}


int main()
{
    head = NULL;
    int M;
    char choice = 'y';
    while(choice =='y'||choice =='Y')
    {
        int chm, option;
        cout<<"Main Menu"<<endl<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Searching "<<endl;
        cout<<"Enter your Choice : ";
        cin>>chm;
        
        switch(chm)
        {
            case 1:
                cout<<"Insertion Menu"<<endl<<endl;
                cout<<"1. Begining"<<endl;
                cout<<"2. End"<<endl;
                cout<<"3. Position"<<endl;
                cout<<"4. Sorted Insertion"<<endl;
                cout<<"Enter Choice of Insertion : ";
                cin>>option;

                cout<<"Enter Marks : ";
                cin>>M;
                res = new_node(M);
                if(res != NULL)
                {
                    cout<<"\n New Node Created"<<endl;
                }

                switch(option)
                {
                    case 1:
                        insert_beg(res);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 2:
                        insert_end(res);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 3:
                        int position;
                        cout<<"Enter position : ";
                        cin>>position;
                        insert_at_position(res,position);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 4:
                        sorted_insert(res);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    default:
                        break;
                }
                cout<<"\nList is: ";
                Result(head);
                break;
            case 2:
                cout<<"Deletion Menu"<<endl<<endl;
                cout<<"1. Begining"<<endl;
                cout<<"2. End"<<endl;
                cout<<"3. Position"<<endl;
                cout<<"Enter Choice of Deletion : ";
                cin>>option;
                switch(option)
                {
                    case 1:
                        delete_beg(head);
                        count--;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 2:
                        delete_end(head);
                        count--;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 3:
                       int p;
                       cout<<"Enter Position : ";
                       cin>>p;
                       delete_at_position(head,p);
                       count--;
                       cout<<"Count is : "<<count<<endl;
                       break;
                    default:
                        break;
                }
                cout<<"\nList is: ";
                Result(head);
                break;
                
            case 3:
                int srch;
                cout<<"Enter element to be searched : ";
                cin>>srch;
                Search(head,srch);
            
                break;
                
            default:
                break;
        }
        cout<<"\n Want to continue (Y/N) : ";
        cin>>choice;
    }
    return 0;
}






