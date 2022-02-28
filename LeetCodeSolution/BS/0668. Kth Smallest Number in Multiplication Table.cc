
class Solution {
public:
    int findKthNumber(int n, int m, int k) {
        int low = 0; int high = n*m;
        int ans=0;
        auto check = [&](int mid){
            int cnt=0;
            for(int i=1;i<=n;i++){
                cnt += min(m,mid/i);
            }
            return cnt;
        };
        while(low<=high){
            int mid = (high+low)>>1;
            if(check(mid)>=k) 
                ans = mid, high = mid-1;
            else 
                low = mid+1;
        }
        return ans;
    }
};

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
