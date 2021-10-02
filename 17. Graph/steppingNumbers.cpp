int count = 0;
    void solve(int n , int m, int start){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current>=n&&current<=m) count++;
            if(start == 0||current>m) continue;
            int front = current*10+(current%10)+1;
            int back = current*10+(current%10)-1;
            if(current%10==0) q.push(front);
            else if(current%10==9) q.push(back);
            else {
               q.push(front); 
               q.push(back);
            }
        }
        
    }
    int steppingNumbers(int n, int m)
    {
        for(int i =0;i<10;i++){
            solve(n,m,i);
        }
        int ans = count ;
        count = 0;
        return ans;
    }
