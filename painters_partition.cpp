// Problem Link: https://www.interviewbit.com/problems/painters-partition-problem/

#define M 10000003
#define int long long int
bool isValid(int A, int B, vector<int> &C, ll ans){
    ll painters = 1;
    ll curr_blocks = 0;
    for(int i = 0;i<C.size();i++){
        if(curr_blocks+C[i] >ans){
            curr_blocks = C[i];
            painters++;
            if(painters > A){
                return false;
            }
        }
        else{
            curr_blocks += C[i];
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll total_units = 0;
     l = 0, r= 0;
    for(int i = 0;i<C.size();i++){
        total_units+=C[i];
        l = max(l,C[i]);
    }
    r = total_units;
    ll final_ans = l;
    while(l <= r){
        ll mid = (l+r)/2;
        if(isValid(A,B,C,mid)){
            final_ans = mid;
            r = mid - 1;
        }
        else{
            l = mid+1;
        }
    }
    return ((final_ans%M)*(B%M))%M;
}