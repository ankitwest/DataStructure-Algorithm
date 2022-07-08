class Solution {
    int dp[101][21][101];
    long long solve(int idx, int prev, vector<int>&houses, vector<vector<int>>&cost,int target,int n){
        if(target==0 and idx>=houses.size()) 
            return 0;
        if(idx>=houses.size()) 
            return INT_MAX;
        if(target<0) 
            return INT_MAX;
        
        if(houses[idx]!=0){ 
            if(prev==houses[idx]) 
                return solve(idx+1,prev,houses,cost,target,n);
            else 
                return solve(idx+1,houses[idx],houses,cost,target-1,n);
        }
        
        if(dp[idx][prev][target]!=-1) 
            return dp[idx][prev][target];
        
        long long ans = INT_MAX;
        for (int color = 1; color <= n; color++) {   
            if(color==prev) 
                ans = min(ans,cost[idx][color-1] + solve(idx+1,prev,houses,cost,target,n));
            else 
                ans = min(ans,cost[idx][color-1] + solve(idx+1,color,houses,cost,target-1,n));
        }
        return dp[idx][prev][target] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));

        int ans =(int)solve(0,0,houses,cost,target,n);
        return ans == INT_MAX ? -1 : ans;
    }
};



class Solution1 {
private:    
    int dp[101][21][101];
    long long solve(int idx, int prev, vector<int>&houses, vector<vector<int>>&cost,int target){
        if(target==0 and idx>=houses.size()) 
            return 0;
        if(idx>=houses.size()) 
            return INT_MAX;
        if(target<0) 
            return INT_MAX;
        
        if(houses[idx]!=0){ 
            if(prev==houses[idx]) 
                return solve(idx+1,prev,houses,cost,target);
            else 
                return solve(idx+1,houses[idx],houses,cost,target-1);
        }
        
        if(dp[idx][prev][target]!=-1) 
            return dp[idx][prev][target];
        
        long long ans = INT_MAX;
        for(int i = 0;i<cost[0].size(); i++){
            if(i+1==prev) 
                ans = min(ans,cost[idx][i] + solve(idx+1,prev,houses,cost,target));
            else 
                ans = min(ans,cost[idx][i] + solve(idx+1,i+1,houses,cost,target-1));
        }
        return dp[idx][prev][target] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));

        int ans = (int)solve(0,0,houses,cost,target);
        return ans == INT_MAX ? -1 : ans;
    }
};

