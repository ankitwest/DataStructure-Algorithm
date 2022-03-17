class Solution {
public:
    int nextPass(vector<vector<int>>& rides,int i){
        int n = rides.size();
        int low = i+1; int high = n-1;
        int ans = n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(rides[mid][0]>=rides[i][1])
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
        
        int next = nextPass(rides,i);
        
        // pick , not pick
        long long incl = rides[i][1]-rides[i][0]+rides[i][2] + solve(rides,next);
        long long excl = solve(rides,i+1);
        
        return dp[i]=max(incl,excl);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(),rides.end());
    dp.resize(rides.size(),-1);
    return solve(rides,0);
    }
};

Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.
