//Problem statement URL:- https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1/?track=DSASP-Hashing&batchId=154
//Hashing approach

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        // Efficient Approach:-step-wise
        
        // 1. Create a set, and insert a[] elements which will be distinct in set
        unordered_set<int> s(a,a+n); 
        
        // 2. Insert b[] elements in the same set
        for(int i=0;i<m;i++){
            s.insert(b[i]); //disinct elements will only be inserted.
        }
        
        // 3. size of our created set s
        return s.size();
    }
};
