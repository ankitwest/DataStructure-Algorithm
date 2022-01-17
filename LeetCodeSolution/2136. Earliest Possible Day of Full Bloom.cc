class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vp; int n = plantTime.size();
        for(int i=0;i<n;i++){
            vp.push_back({growTime[i],plantTime[i]});
        }
        
        sort(vp.rbegin(),vp.rend());
        
        int ans = 0; int grow,plant; int cnt = 0;
        for(int i=0;i<n;i++){
            grow = vp[i].first; plant = vp[i].second;
            cnt += plant;
            ans = max(ans,cnt+grow);
        }
        return ans;
    }
};
