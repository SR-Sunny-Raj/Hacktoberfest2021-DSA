#include<iostream>
using namespace std;


struct list{
int data;
list *link;
};



list * head;

void display_list(){
    list *l=new list();
    if(head==NULL){
        cout<<"List is empty";
    }
    else{ 
        l=head;
        while(l!=NULL){
            cout<<l->data<<" ";
            l=l->link;
        }
    }
}


void insert_at_first(int z){
    list *b=new list();
    b->data=z;
    b->link=NULL;
    if(head==NULL){
     head=b;
    }
    else {
        b->link=head;
        head=b; 
        }
    }

 void insert_at_last(int n){
    list *c=new list();
    c->data=n;
    list *q=head;
    c->link=NULL;
    if(head==NULL){
        head=c;
    }      
    else {
      while(q->link!=NULL){
          q=q->link;
      }
      q->link=c;
        }
}

void insert_at_mid(int a,int b){
    list *d=new list();
    list *q=head;
    d->data=b;                   
    while(q!=NULL){
        if(q->data==a){   
        d->link=q->link;
        q->link=d;
         return;
        }
        q=q->link;
        } 
    
}
   

void delete_first(){
   list *p=head;
   p=p->link;
   head=p;
   }

void delete_last(){
    list *q=head;
    list*t;
    t=head;
    while(q->link!=0){
        t=q;
        q=q->link;
    }  
    if(t==head){
        head=t->link;
    }
    else{
    t->link=NULL;
    }     
}

void delete_any(int a){
    list *q=head;
    list *z=head;
    if(a==q->data){
      head=q->link;
    }
    else{
    while(q!=NULL){
        if(a==q->data){
        z->link=q->link;
        break;
    }
    z=q;
    q=q->link;
    }
 } 
}


void count_list(){
    int count=0;
    list *l=new list();
    if(head==NULL){
        cout<<"List is empty";
    }
    else{
        l=head;
        while(l!=NULL){
        count++;
        l=l->link;
        }
    }
    cout<<count;
}

void get_max_from_list(){
    list*q=head;
    int max=q->data;
    if(head==NULL){
        cout<<0;
    }
    else{
   while(q!=NULL){
       if(max<q->data){
         max=q->data;
       }
       q=q->link;
   }
    }
    cout<< max;
}

void reverse_list(){
    list *q=head;
    list*next=NULL;
    list*prev=NULL;
    while(q!=NULL){
        next=q->link;
        q->link=prev;
        prev=q;
        q=next;
    }
  head =prev;
}

 int main(){
     int size,num1,num2;
     cout<<"Enter how many element you want to give to the list:-\t";
     cin>>size;
     for(int i=0;i<size;i++){
         cout<<"Enter the new number you want to add :-\t";
         cin>>num1;
         insert_at_first(num1);
     }
     cout<<"\n";
     display_list();
     cout<<"\nEnter the number you want to add at last :-\t";
     cin>>num2;
     insert_at_last(num2);
     cout<<"\n";
     display_list();
     cout<<"\nEnter the number after which you want to add new element :-\t";
     cin>>num1;
    cout<<"\nEnter the number  which you want to add :-\t";
    cin>>num2;
    insert_at_mid(num1,num2);
    cout<<"\n";
    display_list();
    cout<<"\nDelete 1st element";
    delete_first();
    cout<<"\n";
    display_list();
    cout<<"\nDelete last element";
    delete_last();
    cout<<"\n";
    display_list();
    cout<<"\nEnter the number you want to delete :-\t";
    cin>>num1;
    delete_any(num1);
    cout<<"\n";
    display_list();
    cout<<"\n";
    cout<<"Number of element left in list : ";
    count_list();
    cout<<"\n";
    cout<<"\nGiving maximum value:  ";
    get_max_from_list();
    cout<<"\nReversed the list : ";
    reverse_list();
    cout<<"\n";
    display_list();
    return 0;
 }


