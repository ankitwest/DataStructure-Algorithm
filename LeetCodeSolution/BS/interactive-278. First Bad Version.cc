// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0; long long high = n; long long ans= 0;
        while(low<=high){
            long long mid = (low+high)>>1;
            if(isBadVersion(mid))
                ans=mid,high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
