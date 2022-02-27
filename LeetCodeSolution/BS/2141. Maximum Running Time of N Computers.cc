class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(auto it:batteries) sum += it;
        
        auto check = [&](long long mid) -> bool{
            long long cnt = 0;
            long long total = mid*n;
             for(auto it:batteries) 
                 cnt += min((long long)it,mid);
            
            return cnt >= total;
        };
        
        long long low=0,high=sum/n; 
        long long ans = -1;
        while(low<=high){
            long long mid = (low+high)/2LL;
            if(check(mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};

Input: n = 2, batteries = [3,3,3]
Output: 4
