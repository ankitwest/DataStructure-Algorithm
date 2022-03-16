//return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.




class Solution {
public:
    int getNextJob(vector<array<int,3>> &jobs,int idx,int n){
        int low = idx+1;int high = n-1; 
        int ans = n;
        while(low<=high){
            int mid = (low+high)>>1;
            if(jobs[idx][1] <= jobs[mid][0])
                ans=mid,high=mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
    vector<int> dp;
    int maxProfit(vector<array<int,3>> &jobs,int idx,int n){
        if(idx==n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int next = getNextJob(jobs,idx,n);
        // take  // not take
        int incl = jobs[idx][2] + maxProfit(jobs,next,n);
        int excl = maxProfit(jobs,idx+1,n);
        
        return dp[idx] = max(incl,excl);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p)
    {
        int n = s.size();
        dp.resize(n,-1);
        vector<array<int,3>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({s[i],e[i],p[i]});
        }
        auto comp = [&](array<int,3> a,array<int,3> b){
            return a[0]<b[0];
        };
        sort(jobs.begin(),jobs.end(),comp);
        return maxProfit(jobs,0,n);
    }
};
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

