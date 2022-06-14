class Solution {
public:
    const int mod = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        
        while(k--){
            int f = pq.top(); pq.pop();
            f++;
            f %= mod;
            pq.push(f);
        }
        
        long long int ans = 1;
        while(!pq.empty()){
            ans *= pq.top(); pq.pop();
            ans %= mod;
        }
        return ans%mod;
    }
};

Input: nums = [0,4], k = 5
Output: 20
Explanation: Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.
Example 2:

Input: nums = [6,3,3,2], k = 2
Output: 216
Explanation: Increment the second number 1 time and increment the fourth number 1 time.
Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
It can be shown that 216 is maximum product possible, so we return 216.
Note that there may be other ways to increment nums to have the maximum product.
