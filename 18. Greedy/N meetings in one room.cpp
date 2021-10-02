    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v(n,{0,0});
        
        for(int i=0; i<n; i++)
            v[i]= {end[i],start[i]};
        
        sort(v.begin(), v.end());
        
        int prev=v[0].first;
        int res=1;
        
        for(int i=1; i<n; i++)
        {
            if(v[i].second > prev)
            {
                res++;
                prev=v[i].first;
            }
        }
        
        
        return res;
    }
