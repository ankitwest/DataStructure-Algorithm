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
