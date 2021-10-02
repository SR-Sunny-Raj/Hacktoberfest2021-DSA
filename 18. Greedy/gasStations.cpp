int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int total = 0;
    int current  = 0;
    int ans =0;
    for(int i=0;i<A.size();i++){
        total+=A[i]-B[i];
        current+=A[i]-B[i];
        if(current<0){
            current =0;
            ans=i+1;
        }
    }
    if(total<0) return -1;
    return ans;
}
