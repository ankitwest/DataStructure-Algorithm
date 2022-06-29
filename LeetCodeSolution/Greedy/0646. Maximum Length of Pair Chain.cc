class Solution {
public:  //greedy
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a ,vector<int>&b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        
        int right = pairs[0][1]; int len = 1;
        for(int i=1;i<pairs.size();i++){
            if(right < pairs[i][0]){
                len++;
                right = pairs[i][1];
            }
        }
        return len;
    }
};


class Solution2 {
public:  //lis  dp
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] < pairs[i][0] and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
