class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
            return n;
            
        vector<vector<int>> dp(n,vector<int>(2e4+5,0));
        int maxi = 2;
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i] - A[j] + 1000;
                dp[i][diff] = max(2, dp[j][diff] + 1);
                maxi = max(maxi,dp[i][diff]);
            }
        }
        return maxi;
    }
};

class Solution2{
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
            return n;
            
        vector<unordered_map<int,int>> dp(n);
        int maxi = 2;
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i] - A[j];
                if(dp[j].find(diff) == dp[j].end()){
                    dp[i][diff] = 2;
                }else{
                     dp[i][diff] = dp[j][diff] + 1;
                }
                maxi = max(maxi,dp[i][diff]);
            }
        }
        return maxi;
    }
};

N = 6
set[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.
