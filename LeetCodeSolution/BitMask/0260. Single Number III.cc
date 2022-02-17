class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        int j=0;
        for(int i=0;i<32;i++){
            if(x&(1<<i)){
                j=i;break;
            }
        }
        cout<<j<<endl;
        int first=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<j)){
                first^=nums[i];
            }
        }
        
        vector<int> v;
        v.push_back(first);
        v.push_back(x^first);
        
        return v;
        
    }
};


Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
