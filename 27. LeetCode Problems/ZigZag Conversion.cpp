class Solution {
public:
    string convert(string s, int numRows) {
    //take a string vector to store the zigzag sequenced strings
        vector <string> temp(numRows, "");
        int row = 0, direction = 1;
        string ans = "";
        
        if(numRows == 1)
            return s;
        
        for(int i = 0; i < s.size(); i++)
        {
            temp[row] += s[i];
            //if reached the last row, move upwards
            if(row == numRows - 1)
                direction = -1;
            if(row == 0)
                direction = 1;
            //if direction is 1, row will be shifted to the next one, else it will be the preceeding one
            row += direction;
            
        }     
        
        for(int i = 0; i < numRows; i++)
        {
            ans += temp[i];
        }
        
        return ans;
    }
};
