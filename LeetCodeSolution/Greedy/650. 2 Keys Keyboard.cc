class Solution {
public:
    int minSteps(int n){
        int curr = 1;
        int prev = 0;
        int ans = 0;
        while(curr<n){
            if(n%curr==0){
                prev = curr;  // copy
                curr += prev;  // paste
                ans += 2;
            }else{
                curr += prev;
                ans++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minSteps(int n) {
//         vector<int> dp(n + 1, INT_MAX / 2);
        
//         dp[0]=dp[1]=0;
//         for(int i=2;i<n+1;++i) {
//             for(int j=1;j*j<=i;++j) {
//                 if(i%j==0) {
//                     int other = i/j;
//                     dp[i] = min({dp[i], i/j+dp[j], i/other+dp[other]});
//                 }
//             }
//         }
        
//         return dp[n];
//     }
// };
