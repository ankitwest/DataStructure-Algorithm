class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index,vector<vector<int>>& piles,int k){
        if(index==piles.size())
            return 0;
        if(dp[index][k]!=0)
            return dp[index][k];
        
        int maxi = 0; int sum = 0;
        //either don't take from that pile
        maxi = max(maxi , solve(index+1,piles,k));
        
        for(int i=0;i<piles[index].size();i++){
            // or take certain prefix from that pile as much we can take
            sum += piles[index][i];
            if(k-(i+1)>=0) maxi = max( maxi , sum + solve(index+1,piles,k-(i+1)));
        }
        return dp[index][k] = maxi;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.resize(n+1,vector<int>(k+1,0));
        return solve(0,piles,k);
    }
};

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
