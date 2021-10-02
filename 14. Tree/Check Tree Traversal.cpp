// Problem statement: Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

// Problem link: https://practice.geeksforgeeks.org/problems/cb02d40f50b0113c47cd9036e5f340bb51b32289/1

// Solution:- 

bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
        if (N == 0)
            return 1;
     
        if (N == 1)
            return (preorder[0] == inorder[0])
                   && (inorder[0] == postorder[0]);
     
        int index = -1, f = 0;
        for (int i = 0; i < N; ++i)
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }
       
        if(index != -1){
          for(int i = 0; i < N; i++)
            if(preorder[0] == postorder[i]){f = 1; break;}
        }
     
        if (index == -1 || f == 0) return 0;
      
        int leftTree = checktree(preorder + 1, inorder, postorder, index);
     
        int rightTree = checktree(preorder + index + 1, inorder + index + 1,
                        postorder + index, N - index - 1);
     
       
        return (leftTree && rightTree);
    } 
