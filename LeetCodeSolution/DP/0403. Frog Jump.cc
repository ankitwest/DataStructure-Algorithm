class Solution {
public:
    unordered_map<int, int>m;
    vector<vector<int>> dp;
    bool solve(vector<int>& stones,int i,int k){
        if(k<=0)
            return false;
        if(i<0 or i>=stones.size())
            return false;
        
        if(i==stones.size()-1) 
            return true;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        bool ans = false;
        if(m.count(stones[i]+k))
            ans = ans | solve(stones,m[stones[i]+k],k);
        if(i>0 and m.count(stones[i]+k+1))
            ans = ans | solve(stones,m[stones[i]+k+1],k+1);
        if(i>0 and m.count(stones[i]+k-1))
            ans = ans | solve(stones,m[stones[i]+k-1],k-1);
        
        return dp[i][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n,vector<int>(n,-1));
        int k = 1; 
        for(int i=0;i<n;i++) 
            m[stones[i]] = i;
        return solve(stones,0,k);
    }
};

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
