#include<bits/stdc++.h>

using namespace std;

/*
    Given a Sorted Matrix and a Target Element, design an efficient Algorithm to Search for that element in that Matrix.

    A Sorted Matrix follows two rules:
        1) Integers in each row are sorted from left to right.
        2) The first integer of each row is greater than the last integer of the previous row.

    A Sorted Matrix looks like this:

             1 |  3 |  5 |  7
            10 | 11 | 16 | 20
            23 | 30 | 34 | 60

*/


int get_row(vector<vector<int>>m, int target)
{
    int low = 0 , high = m.size()-1 , mid = (low+high)/2;
        
    while(low<=high)
    {
        // Getting the middle row
        mid = (low +high)/2;
        
        // If the row's first element is greater than target,then as per the condition, this row cannot contain the Target Element and so we modify the Search Space according to the Rule of Binary Search
        if(m[mid][0] > target)
            high = mid - 1;
        
        // If the row's first element is the Target,then we return the Index of the Corresponding Row
        if(m[mid][0] == target)
            return mid;
        
        /*
        If the row's first element is less than the Target,then two conditions may arise

        1) The Row next to the Present Row has its first element greater than the Target, and so it is clear that the Present Row might contain the Target Element within it.

        2) The Row next to the Present has its first element lesser than the Target, and so it is clear that we have to modify the Search space whose Start now becomes the Next Row
        
        */

        if(m[mid][0] < target)
        {

            // Done to avoid Runtime Error. If the Present row has its first element less than the target and it is also the last Row, so there is no point in checking the next row. But there is a Possibility that the Present Row might contain the Target Element and so we return the Index of the Present Row.
            if(mid+1 >= m.size())
                return mid;
                
            if(m[mid+1][0] > target)
                return mid;
                
            else
                low = mid + 1;
        }

    }
        
    return -1;
}


bool search_in_matrix(vector<vector<int>> &matrix, int target)
{
    if(matrix.size() == 0)
        return false;

    // Getting the Required row in which there is a possibility of getting the target_element
    int row_num = get_row(matrix,target);

    // If it is == -1, then we return false
    if(row_num == -1)
        return false;

    // Doing Binary Search for the Given Row
    int low = 0 ,high = matrix[row_num].size() - 1 , mid = (low +high)/2;
        
    while(low<=high)
    {
        mid = (low +high)/2;
            
        if(matrix[row_num][mid]  == target)
            return true;
            
        if(matrix[row_num][mid]  < target)
            low = mid + 1;
            
        if(matrix[row_num][mid]  > target)
            high = mid - 1;
    }
        
    return false; 
}


// Driver Code
int main()
{
    vector<vector<int>> v;
    
    v.push_back({1,3,5,7});
    v.push_back({10,11,16,20});
    v.push_back({23,30,34,60});


    int target = 3;

    cout<<search_in_matrix(v,target);
}
