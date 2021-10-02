vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>v;

        while(!q.empty())
        {
            int size=q.size();
            vector<int>v1;
            while(size--)
            {
                Node*t=q.front();
                v1.push_back(t->val);
                for(auto i:t->children)
                {
                    q.push(i);
                }
                q.pop();
            }
           v.push_back(v1); 
        }
        return v;
    }
};