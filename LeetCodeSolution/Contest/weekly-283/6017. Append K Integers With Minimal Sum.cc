class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x:nums) m[x]++;
        
        long long ans = 0;
        long long start = 1;
        for(auto [x,y]:m){
            long long l = start;
            long long r = x;
            if(k>(r-l)) k-= (r-l);
            else break;
            
            ans += (r*(r-1LL))/2LL - (l*(l-1LL))/2LL;
            start = r+1;
        }
        long long l = start;
        long long r = start+k;
        ans += (r*(r-1LL))/2LL - (l*(l-1LL))/2LL;
        return ans;
    }
};

Example 1:

Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.
