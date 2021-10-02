#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

//Boyre-moore matching can work with pattern of different characters
// Not sure this will work for all cases

int main() 
{         char t[20],p[4];
          int i,j,k,n,flag,s;
                  cout<<"Enter 4 charaters for pattern & 20 characters for text\n";
                  cout<<"Input 4 characters pattern: "<<endl;
                   for(i=0;i<4;i++) { scanf("%c" ,&p[i]);}; 
                   cout<<"Input 20 characters text: "<<endl;		               
                   for(i=0;i<20;i++) { scanf("%c" , &t[i]);};

                  i=-1;k=-1;

                  do{ 
                      j=k;
                          do{i=i+1;j=j+1;} while (t[j]==p[i] && i<4);

                          if (i<4) 
                          {
                          cout<<"Match not found\n";
                          flag=0; 
                                  for(n=3;n>=0;n--)
                                  {
                                      if(p[n]==t[j])
                                      {
                                            flag=1;
                                            s=n;
                                            cout<<"n= "<<n<<endl;
                                      }
                                  }
                          
                           if(flag==0){ i=-1; k=k+4;cout<<"k= "<<k<<endl;}
                           else
                           { 
                              i=-1;
                              k=j-s-1;
                              cout<<"k= "<<k<<endl;
                           }
                          }

                          if(i==4) {cout<< "Match found at "<<k+1;break;}

                     }  while( k<20);

                  if(i<4)cout<<"Match not found\n";

    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

