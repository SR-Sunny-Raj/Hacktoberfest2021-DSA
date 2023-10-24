vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* t = q.front();
       q.pop();
       while(t){
           if(t->left) q.push(t->left);
           ans.push_back(t->data);
           t = t->right;
       }
   }
   return ans;
}
