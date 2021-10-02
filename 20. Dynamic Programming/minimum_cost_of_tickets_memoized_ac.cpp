class Solution {
public:
    int solve(vector<int>& day, vector<int>& cost, int start){
        //recursive code
        int n = day.size();
        if(start>=n)
            return 0;
        int i;
        
        for(i = start; i<n && day[i]<day[start]+1; i++);
        int cost_day = cost[0] + solve(day, cost, i);
        
        for(i = start; i<n && day[i]<day[start]+7; i++);
        int cost_week = cost[1] + solve(day, cost, i);
        
        for(i = start; i<n && day[i]<day[start]+30; i++);
        int cost_month = cost[2] + solve(day, cost, i);
        
        return min(cost_day, min(cost_month, cost_week));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days, costs, 0);
    }
};