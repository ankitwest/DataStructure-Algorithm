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
