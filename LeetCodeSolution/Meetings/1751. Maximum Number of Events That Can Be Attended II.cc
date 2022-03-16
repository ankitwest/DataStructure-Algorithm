class Solution {
public:
    int nextEvent(vector<vector<int>>& events, int i){
        int low = i+1; int high = events.size()-1;
        int ans = events.size(); int val = events[i][1];
        while(low<=high){
            int mid = (low+high)/2;
            if(events[mid][0]>val)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
    vector<vector<int>>dp; int k1;
    int solve(vector<vector<int>>& events, int i, int k){
        if(i>=events.size() or k==k1)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int next = nextEvent(events,i);
        
        // pick , not pick
        int incl = events[i][2] + solve(events,next,k+1);
        int excl = solve(events,i+1,k);
        
        return dp[i][k] = max(incl,excl);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size(); k1=k;
        sort(events.begin(),events.end());
        dp.resize(n+1,vector<int>(k,-1));
        return solve(events,0,0);
    }
};



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
