	int search(string pat, string txt) {
	    // code here
	    int ans=0;
	    unordered_map<char,int>m;
	    
	    for(auto i: pat)
	        m[i]++;
	    
	    int count = m.size(), k = pat.size();
	    int i=0,j=0;
	    
	    while(j < txt.size())
	    {
	        if(m.find(txt[j])!=m.end())
	        {
	            m[txt[j]]--;
	            if(m[txt[j]]==0)count--;
	        }
	        if(j-i+1<k)
	            j++;
	        else if(j-i+1==k)
	        {
	            if(count==0)ans++;
	            if(m.find(txt[i])!=m.end())
	            {
	                m[txt[i]]++;
	                if(m[txt[i]]==1)count++;
	            }
	            i++;
	            j++;
	        
	        }
	     
	    }
	    return ans;
	}
