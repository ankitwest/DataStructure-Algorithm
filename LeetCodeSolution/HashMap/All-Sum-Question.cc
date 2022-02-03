//Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int no1= nums[i];
            int no2= target- no1;
            if(m.find(no2)!=m.end()){
                int j =  m[no2];
                ans.push_back(i),ans.push_back(j);
            }
            m[no1]=i;
        }
        return ans;
    }
};



// Three Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size(); 
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int left=1;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) 
                continue;
            int left = i+1,right=n-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0)
                    right--;
                else if(nums[i]+nums[left]+nums[right]<0)
                    left++;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                     while(nums[left-1]==nums[left] && left<right)
                        left++;
                }
            }
        }
        return ans;
    }
};

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0]
Output: []




// 4 Sum

class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        vector<vector<int>> ans;  
        set<vector<int>> store;   // to store and remove the duplicate answers
        
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n ; j++){
                int new_target  =  target - nums[i] - nums[j];
                int left = j+1 , right = n-1;
                
                while(left < right){
                    int sum = nums[left] + nums[right];
                    
                    if(sum > new_target) right--;
                    else if(sum < new_target ) left++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;
                    }
                }
            }
        }
        
        for(auto i : store){
            ans.push_back(i);  // store the answers in an array(ans)
        }
        
        return ans;
    }

};



Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]




// 4 Sum ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m;
        for(auto a:nums1){
            for(auto b:nums2){
                m[a+b]++;
            }
        }
        
        int ans=0;
        for(auto c:nums3){
            for(auto d:nums4){
                if(m.find(-c-d)!=m.end())
                    ans += m[-c-d];
            }
        }
        return ans;
    }
};
Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
