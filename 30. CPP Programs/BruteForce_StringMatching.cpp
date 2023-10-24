
#include <cstdlib>
#include <iostream>
#include<stdio.h>

using namespace std;

// Brute force matching

int main() 
{  
          char t[20],p[4];
          int i,j,k;

		  cout<<"Enter 4 characters for pattern & 20 characters for text\n";
		  // cannot use cin in input because cin does not take blank space into character counting
		  
		   cout<<"Input 4 characters pattern: "<<endl;
           for(i=0;i<4;i++) { scanf("%c" ,&p[i]);};
           cout<<"Input 20 characters text: "<<endl;		   
		   for(i=0;i<20;i++) { scanf("%c" , &t[i]);};

		  i=-1;k=-1;

		  do{ 
              j=k;
			  do { i=i+1;j=j+1;} while (t[j]==p[i] && i<4);

			  if (i<4) {i=-1; k=k+1;}
              else {cout<< "Match found at "<<k+1;break;}

		     }  while( k<20);

		  if(i<4)cout<<"Match not found\n";

    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

