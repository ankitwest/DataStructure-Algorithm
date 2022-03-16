class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events,int i,int eventsAttended){
        if(i==events.size() or eventsAttended==2)
            return 0;
        
        if(dp[i][eventsAttended]!=-1)
            return dp[i][eventsAttended];
        
        vector<int> ans = {events[i][1],INT_MAX,INT_MAX};
        int next = upper_bound(events.begin(),events.end(),ans) - events.begin();
        
        //pick  // not pick
        int incl = events[i][2] + solve(events,next,eventsAttended+1);
        int excl = solve(events,i+1,eventsAttended);
        
        return dp[i][eventsAttended] = max(incl,excl);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        dp.resize(n,vector<int>(2,-1));
        sort(events.begin(),events.end());
        
        return solve(events,0,0);
    }
};

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
  
  Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
  
  Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
