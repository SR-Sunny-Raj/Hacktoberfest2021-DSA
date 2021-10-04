#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 6

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
	return key%SIZE;
}

void insert(int key,int data){
	struct DataItem *item=(struct DataItem*)malloc(sizeof(struct DataItem));
	item->data=data;
	item->key=key;
	
	int hashIndex = hashCode(key);
	
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
		++hashIndex;
		
		hashIndex %=SIZE;
	}
	hashArray[hashIndex]=item;
}



struct DataItem *search(int key) {
   int hashIndex = hashCode(key);  
   
   while(hashArray[hashIndex] != NULL) {
   	
      if(hashArray[hashIndex]->key == key)
      	return hashArray[hashIndex]; 
	  
      ++hashIndex;
      
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}


void display(){
	int  i;
	for (i=0;i<SIZE;i++){
		if(hashArray[i] != NULL){
			printf("(%d,%d)",hashArray[i]->key,hashArray[i]->data);
		}else{
			printf(" ");
		}
	
		}
		printf("\n");
}





int main(){
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1,12 );
   insert(2,34 );
   insert(3, 11);
   insert(4, 9);
   insert(5, 3);
   
   display();
   
   int setB[] = {2,1,3,5};
   int j;
   for(j=1;j<sizeof(setB);j++){
   		item=search(setB[j]);
   		 
   	
   }
   if(item != NULL) {
     		 printf("Element  not found\n");
     		
  	 } else {
      	printf("Element  found\n");
      
   	}
  
  
}
