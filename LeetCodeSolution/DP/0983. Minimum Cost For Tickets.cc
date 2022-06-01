class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365+1,INT_MAX);
        unordered_set<int> s(days.begin(),days.end());
        
        dp[0] = 0;
        for(int i=1;i<=365;i++){
            if(s.find(i)==s.end())
                dp[i] = dp[i-1];
            else{
                int day1 = dp[max(0,i-1)] + costs[0];
                int day7 = dp[max(0,i-7)] + costs[1];
                int day30 = dp[max(0,i-30)] + costs[2];
                dp[i] = min({dp[i],day1,day7,day30});
            }
        }
        return dp[365];
    }
};

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel
