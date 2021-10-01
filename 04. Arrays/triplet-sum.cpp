// Find the triplet that sum to a given value

bool find3Numbers(int A[], int n, int x)
{
    int l, r;
    sort(A, A+n);
    for (int i=0; i<n-1; i++){
        l = i+1;
        r=n-1;
        while(l<r)
        {
            if(A[i] + A[l] + A[r] == x)
                return true;
            else if(A[i] + A[l] + A[r] < x)
                l++;
            else
                r--;
        }
    }
    return false;
}
