class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long l = 0, r = 1e14;
        long long ans = r;
        auto check = [&](long long mid){
            long long t = 0;
            for(int i=0;i<time.size();i++){
                t += mid/time[i];
            }
            return t>=totalTrips;
        };
        while(l<=r){
            long long mid = (l+r)>>1;
            if(check(mid))
                ans = mid, r = mid-1;
            else 
                l = mid+1;
        }
        return ans;
    }
};
Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
Example 2:

Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
