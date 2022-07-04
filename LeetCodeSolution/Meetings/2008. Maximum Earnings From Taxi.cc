class Solution1 {
    int nextPass(vector<vector<int>>& rides,int i){
        int n = rides.size();
        int low = i+1; int high = n-1;
        int ans = n; int end = rides[i][1];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(rides[mid][0] >= end)
                ans = mid, high = mid-1;
            else 
                low = mid+1;
        }
        return ans;
    }
    vector<long long> dp;
    long long solve(vector<vector<int>>& rides,int i)
    {
        if(i==rides.size()) 
            return 0;
        if(dp[i]!=-1) 
            return dp[i];
        
        int next_index = nextPass(rides,i);
        
        // pick , not pick
        int dollar = rides[i][1]-rides[i][0]+rides[i][2];
        long long incl = dollar + solve(rides,next_index);
        long long excl = solve(rides,i+1);
        
        return dp[i] = max(incl,excl);
    }
public:
    long long maxTaxiEarnings(int t, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int n = rides.size();
        dp.resize(n,-1);
        return solve(rides,0);
    }
};



//tabulation
class Solution {
    int nextPass(vector<vector<int>>& rides,int i){
        int n = rides.size();
        int low = i+1; int high = n-1;
        int ans = n; int end = rides[i][1];
        while(low <= high){
            int mid = low+(high-low)/2;
            if(rides[mid][0] >= end)
                ans = mid, high = mid-1;
            else 
                low = mid+1;
        }
        return ans;
    }
public:
    long long maxTaxiEarnings(int t, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        
        int n = rides.size();
        long long dp[n+1]; 
        memset(dp,0,sizeof(dp));
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
            int dollar = rides[i][1]-rides[i][0]+rides[i][2];
            int next_index = nextPass(rides,i);
            dp[i] = max(dp[i+1], dp[next_index] + dollar);
        }
        return dp[0];
    }
};

Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.
