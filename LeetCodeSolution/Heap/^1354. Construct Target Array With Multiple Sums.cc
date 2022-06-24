class Solution {
public:
    bool isPossible(vector<int>& nums) {
        long long int sum = 0; int n = nums.size();
        priority_queue<int> pq;
        for(auto i:nums){
            sum += i;
            pq.push(i);
        }
        
        while(pq.top()!=1){
            int num = pq.top(); pq.pop();
            sum -= num;
            if(sum == 1) return true;   //{1, 10000}
            if(num <= sum or sum == 0 or num % sum == 0) return false;
            int dep = num % sum;
            sum += dep;
            pq.push(dep);
        }
        return true;
    }
};

Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
