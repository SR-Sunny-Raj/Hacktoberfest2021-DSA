// Problem Link: https://www.interviewbit.com/problems/allocate-books/


bool isValidOrder(vector<int> &A, int B, int ans){
    int curr_books = 0;
    int students = 1;
    for(int i = 0;i<A.size();i++){
        if(curr_books + A[i] > ans){
            curr_books = A[i];
            students++;
            if(students > B){
                return false;
            }
        }
        else{
            curr_books += A[i];
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()){
        return -1;
    }
    int l = *max_element(A.begin(),A.end());
    int r = 0;
    for(int i = 0;i<A.size();i++){
        r+=A[i];
    }
    int final_ans = l;
    while(l <= r){
        int mid = (l+r)/2;
        if(isValidOrder(A,B,mid)){
            final_ans = mid;
            r = mid - 1;
        }
        else{
            l = mid+1;
        }
    }
    return final_ans;
}
