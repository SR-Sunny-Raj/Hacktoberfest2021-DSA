#include<iostream>
using namespace std;

class stack{
    public:
    int top;
    int arr[5];

    stack(){
        top = -1;
        for(int a;a<=5;a++){
            arr[a]=0;
        }
    }

    bool IsFull(){
        if(top==5){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int val){
        if(IsFull()){
            cout<<"stack overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    int pop(){
        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else{
            int popvalue;
            arr[top]=popvalue;
            arr[top]=0;
            top--;
            return popvalue;
        }
    }

    int Display(){
        for(int i= 4;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }

};

int main(){

stack s1;
int val,num;
do{
    cout<<"enter an numer according to operation"<<endl;
    cout<<"1.To check stack is full"<<endl;
    cout<<"2.To check stack is empty"<<endl;
    cout<<"3.To push the value"<<endl;
    cout<<"4.To pop the value"<<endl;
    cout<<"5.To display values in stack"<<endl;
    cout<<"Enter 0 to exit"<<endl;

    cin>>num;
    switch (num)
    {

    case 1:
    if(s1.IsFull())
    cout<<"stack is full"<<endl;
    else
    cout<<"stck is not full"<<endl;
        break;

    case 2:
    if(s1.IsEmpty())
    cout<<"stck is empty"<<endl;
    else
    cout<<"stack is not empty"<<endl;
        break;

    case 3:
    cout<<"enter a valur to push"<<endl;
    cin>>val;
    s1.push(val);
        break;

    case 4:
    cout<<"pop funcltion has initiated"<<endl;
    s1.pop();
        break;

    case 5:
    s1.Display();
        break;

    
    default:
        break;
    }

}while(num!=0);

    return 0;
}
