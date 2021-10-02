vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here -  rahul
        vector <long long> ans;
        stack <long long> s;
        
        for(int i=n-1; i>=0;i--)
        {
            if(s.empty())
                ans.push_back(-1);
            else if(!s.empty() && arr[i]>=s.top())
            {
                while(!s.empty() && arr[i]>=s.top())
                    s.pop();
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top()); 
            }
            else
            {
                ans.push_back(s.top());    
            }
            
            s.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
