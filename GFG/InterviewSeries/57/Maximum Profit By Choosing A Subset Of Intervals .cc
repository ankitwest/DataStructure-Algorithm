class Solution {
    int findNextIndex(vector<vector<int>> &intervals,int i){
        int n = intervals.size();
        int ans = n; int end = intervals[i][1];
        int low = i+1;int high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(intervals[mid][0] >= end)
                ans = mid, high = mid-1;
            else 
                low = mid + 1;
        }
        return ans;
    }
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
            int next_index = findNextIndex(intervals,i);
            dp[i] = max(dp[i+1], dp[next_index] + intervals[i][2]);
        }
        return dp[0];
    }
};

Input:
n = 3
intervals = {
{1, 2, 4},
{1, 5, 7},
{2, 4, 4}
}
Output:
8
Explanation:
One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
profit of 8.
