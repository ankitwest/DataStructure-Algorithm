
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int> &piles){
        if(l>r)
            return 0;
        if(l==r)
            return piles[l];
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int case1 = piles[l] - solve(l+1,r,piles);
        int case2 = piles[r] - solve(l,r-1,piles);
        
        return dp[l][r] = max(case1,case2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1,piles)>0;
    }
};


// *Case 1:
// Alex takes (i)th pile than array became (i+1, j)
// now if Lee will take the (i+1)th pile then array became (i+2, j)
// and if Lee will take the (j)th pile then array became (i+1, j-1)
// => Lee is supposed to take the maxi among 2 choices then Alex will reamin with min of these 2 choices

// Case 2:
// Alex takes (j)th pile than array became (i, j-1)
// now if Lee will take the (i)th pile then array became (i+1, j-1)
// and if Lee will take the (j-1)th pile then array became (i, j-2)
// => Lee is supposed to take the maxi among 2 choices then Alex will reamin with min of these 2 choices*
class Solution2 {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++)
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0) dp[i][j] = piles[i];
                else if(gap == 1) dp[i][j] = max(piles[i], piles[j]);
                else{
                    int case1 = piles[i] + min(dp[i+2][j], dp[i+1][j-1]);  // as max is taken by lee so what left is minimum
                    int case2 = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(case1, case2);    // maximum of these 2 cases
                }
            }
        return dp[0][n-1]>0;
    }
};

