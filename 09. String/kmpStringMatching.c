//Implementation of KMP Algorithm for pattern matching in string in C

#include<stdio.h>
#include<string.h>

void kmp_match(char text[],char pat[]) {
  int i,j=0,k,count=0,f=1,len,splen[50]={0};
  len=strlen(pat);

  if(strlen(text)<len) {
    printf("NOT FOUND\n");
    return;
  }

  for(i=1;i<len;i++) {
    if(pat[j]==pat[i]) {
        splen[i]=splen[i-1]+1;
        j++;
    }
    else {
      splen[i]=0;
      j=0;
    }
  }

  i=0;
  k=0;
  while(i<=strlen(text)) {
    f=1;
    for(j=k;j<len;j++) {
      if(text[i]==pat[j]) i++;
      else{
        k=splen[j];
        f=0;
        if(j==0)
          i++;
        break;
      }
    }
    if(f==1) {
      printf("Pattern found starting at index: %d\n",i-len);
      k=splen[len-1];
      count++;
    }
  }

  printf("...TOTAL %d MATCHING FOUND...\n",count);
}

int main() {
  char text[100],pat[50];
  printf("Enter the text to search in: ");
  scanf("%s",text);
  printf("Enter the pattern to search: ");
  scanf("%s",pat);
  kmp_match(text,pat);
  return 0;
}
