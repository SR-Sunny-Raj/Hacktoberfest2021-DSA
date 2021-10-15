//We have n chips, where the position of the ith chip is position[i].
/*We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:
position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.*/
//Return the minimum cost needed to move all the chips to the same position.
/*
Input 1: position = [1,2,3]
Output 1: 1
Input 2: position = [2,2,2,3,3]
Output 2: 2
Input 3: position = [1,1000000000]
Output 3: 1
*/


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(int i=0;i<position.size();i++)
        {
            if(position[i]%2==0)  //We just need to count the number of chips at the even positions 
                                   //and the number of chips at the odd positions and return the smaller one.
                even++;
            else
                odd++;
        }
        return min(even,odd);
    }
};