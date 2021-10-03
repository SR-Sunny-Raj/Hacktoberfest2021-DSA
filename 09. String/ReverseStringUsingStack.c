#include <stdio.h>
#include <string.h>

#define max 100
char st[100];
int top = -1;

void push(char ch) {
    top++;
    if(top < max) {
        st[top] = ch;
    }
}

char topEle() {
    return st[top];
}

void pop() {
    top--;
}

int main() {
    char str[100];
    printf("Enter any string to reverse: ");
    scanf("%[^\n]%*c", str);
    for(int i = 0; i < strlen(str); ++i) {
        push(str[i]);
    }
    for(int i = 0; i < strlen(str); ++i) {
        printf("%c", topEle());
        pop();
    }
    return 0;
}
