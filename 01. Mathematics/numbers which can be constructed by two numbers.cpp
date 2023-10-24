 int getCount(int x, int y, int n) {
       bool arr[n+1];
       memset(arr,false,sizeof(arr));
       int result=0;
       if(x<=n)
       {
       arr[x]=true;
      // result++;
       }
       if(y<=n)
       {
           arr[y]=true;
        //   result++;
       }
       for(int i=min(x,y);i<=n;i++)
       {
           if(arr[i])
           {
               if(i+x<=n)
               {
                   arr[i+x]=true;
                  // result++;
               }
               if(i+y<=n)
               {
                   arr[i+y]=true;
                   //result++;
               }
               result++;
           }
       }
       return result;
       
    }