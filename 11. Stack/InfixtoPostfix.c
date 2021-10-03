#include<stdio.h>
#include<stdlib.h>

#define N 20
int top=-1;

int push(char s[],char c)
{
    if(top <= (N-1))
        s[++top]=c;
    else
        printf("StackOverflow");
    return 0;
}

char pop(char s[]){
    if(top > (-1))
        return (s[top--]);
    else
        printf("StackUnderflow");
}

char read(char s[]){
    if(top >= 0)
        return(s[top]);

}

int prec(char ch){
    if(ch=='^' || ch=='%') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
}

int isoperand(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 1;
    else
        return 0;

}
void infixtopostfix(char infix[]){
    char s[N];
    char postfix[N]={0};

    int i=0,p=0;

    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[p]=infix[i];
            p++;
            i++;
        }
        else if(infix[i]=='('){
            push(s,infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(read(s)!='('){
                postfix[p++]=pop(s);
            }
            pop(s);
            i++;
        }
        else{
            if(top==-1 || read(s)=='('){
                push(s,infix[i++]);
                }
            else if(prec(infix[i])>prec(read(s))){
                push(s,infix[i]);
                i++;
            }
            else
                postfix[p++]=pop(s);
        }
}

while(top!=-1)
    postfix[p++]=pop(s);
printf("%s ",postfix);
}


int main(){
    char infix[20];
    printf("Infix expression = ");
    scanf("%s",&infix);
    printf("Postfix Expression = ");
    infixtopostfix(infix);
    return 0;
}

/* ""OUTPUT""

Infix expression = a+b*c-d/e*h
Postfix Expression = abc*+de/h*-

*/

