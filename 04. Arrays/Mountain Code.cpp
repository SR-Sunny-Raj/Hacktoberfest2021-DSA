#include <bits/stdc++.h>
using namespace std;
void mount(vector<int>arr1)
{
  int n= arr1.size(), lar=0;
  //check peak
  for(int i=1;i<=n-2;)
  {
     if(arr1[i]>arr1[i-1] and arr1[i]>arr1[i+1])
     {
       int j=i,cnt=1;
       //left
       while(j>=1 and arr1[j]>arr1[j-1] )
       {
          cnt++;
          j--;
       }
       //right
       while(i<=n-2 and arr1[i]>arr1[i+1] )
       {
          cnt++;
          i++;
       }
       lar=max(cnt,lar);
     }
     else{
       i++;
     }
  }
  cout<<lar;
} 

int main() {
 vector<int> arr={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
 mount(arr);
}
