class Solution
{
public:
    int climbStairs(int n)
    {
        int second = 1, first = 0, third = 0;
        for (int i = 0; i < n; i++)
        {
            third = second + first;

            first = second;
            second = third;
        }
        return third;
    }
};