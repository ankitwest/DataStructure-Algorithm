class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        unordered_map<string,int> m;
        for(auto num:nums){
            m[num]++;
        }
        
        int pairs = 0;
        for(int i=0;i<target.size();i++){
            string a = target.substr(0,i);
            string b = target.substr(i);
            if(a==b)
                pairs += m[a]*(m[a]-1);
            else
                pairs += m[a]*m[b];
        }
        return pairs;
    }
};
Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
