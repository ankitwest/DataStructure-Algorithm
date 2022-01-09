class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> perf;
        for(int i=0;i<n;i++)
            perf.push_back({efficiency[i],speed[i]});
        
        sort(perf.rbegin(),perf.rend());
        
        priority_queue<int,vector<int>,greater<int>> minpq;
        
        long sum = 0; long ans = 0;
        for(auto [eff,speed]:perf){
            sum += speed;
            minpq.push(speed);
            
            if(minpq.size()>k){
                sum -= minpq.top();
                minpq.pop();
            }
            
            ans = max(ans,eff*sum);
        }
        long mod= 1e9+7;
        ans = ans%mod;
        return ans;
    }
};


Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
