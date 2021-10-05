//Evaluate a given postfix expression using stack

#include <iostream>
#include <math.h>

using namespace std;

class node
{
public:
    float data;
    node *link;
};

class stack_
{
public:
    node *top;
    void push(float);
    float pop();
    void display();
    bool isEmpty();
    void postfixEval(string);
    void add();
    void sub();
    void mul();
    void div();
    void power();
    stack_(){top=0;};
};

void stack_::push(float data)
{
    node * newnode;
    newnode=(node *)new(node);      //create a new node
    newnode->data=data;
    newnode->link=top;
    top=newnode;            //move top to new node
}

float stack_::pop()
{
    if(isEmpty())
    {
        cout<<"stack is empty"<<endl;
    }
    else{
    node*tmp;
    tmp=top;
    top=top->link;          //update top
    float popped=tmp->data;
    delete tmp;
    return popped;      //return the data popped
    }
    return -1;
}


bool stack_::isEmpty(){
    if(top==0){             //if top is NULL, queue is empty
        return true;
    }
    else{
        return false;
    }
}


void stack_::add(){
    float op2=pop();            //pop top and store in op2
    float op1=pop();            //pop top and store in op1
    push(op1+op2);            //push the result of op1+op2
}


void stack_::sub(){
    float op2=pop();            //pop top and store in op2
    float op1=pop();            //pop top and store in op1
    push(op1-op2);            //push the result of op1-op2
}


void stack_::mul(){
    float op2=pop();            //pop top and store in op2
    float op1=pop();            //pop top and store in op1
    push(op1*op2);            //push the result of op1*op2
}


void stack_::div(){
    float op2=pop();            //pop top and store in op2
    float op1=pop();            //pop top and store in op1
    push(op1/op2);            //push the result of op1/op2
}

void stack_::power(){
    float op2=pop();            //pop top and store in op2
    float op1=pop();            //pop top and store in op1
    push(pow(op1,op2));            //push the result of op1^op2
}


void stack_::postfixEval(string str){
    if(!isdigit(str[0]) || !isdigit(str[2]) || isdigit(str[str.size()-1])){           //check if the entered expression is invalid
        cout<<"Invalid Expression!!"<<endl;
        return;
    }
    for(int i=0;str[i]!='\0';i++){      //traverse the string
            int c=0;
        if (isdigit(str[i])){           // if digit, convert the digits before the ',' to a number
        for(;str[i]!=',';i++){
            c=(int)str[i]-'0'+c*10;
        }
        push(c);                        //push the number in the stack
        }
        else{                           //if character is not a number
            switch(str[i]){
            case '+':add();
            i++;
            break;
            case '-':sub();
            i++;
            break;
            case '*':mul();
            i++;
            break;
            case '/':div();
            i++;
            break;
            case '^': power();
            break;
            }
        }
    }
    cout<<"answer : "<<pop();
}


int main()
{
    stack_ s;
    string postfix;
    cout<<"Enter a postfix expression separated by ',' : ";
    cin>>postfix;
    cout<<"Expression: "<<postfix<<endl;
    s.postfixEval(postfix);
    return 0;
}

/*

=======================================================================================
TIME COMPLEXITIES:
void push()     =       O(1)
int pop()       =       O(1)
void peek()     =       O(1)
bool isEmpty()  =       O(1)
void add()      =       O(1)
void sub()      =       O(1)
void mul()      =       O(1)
void div()      =       O(1)
float postfixEval()=    O(n)
=======================================================================================

OUTPUT:

Enter a postfix expression separated by ',' : 23,2,*,30,2,/,+,10,-
Expression: 23,2,*,30,2,/,+,10,-
answer : 51
*/
