
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;  lis.push_back(nums[0]); 
        
        for(int i=1;i<n;i++){
            int num = nums[i];
            if(num > lis.back()){
                lis.push_back(num);
            }else{
                int idx = lower_bound(lis.begin(),lis.end(),num)-lis.begin();
                lis[idx] = num;
            }
        }
        return lis.size();
    }
};


//not good
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(auto num:nums){
            int l = 0, h = lis.size()-1;
            while(l<=h){
                int mid = (l+h)/2;
                if(num > lis[mid]) l = mid+1;
                else h = mid-1;
            }
            int idx = l;
            if(idx==lis.size()) lis.push_back(num);
            else lis[idx] = num;
        }
        return lis.size();
    }
};

// [1,7,8,4,5,6,-1,9]
// Similarly, we pick 8 as well since it's greater than 7.   sub=[1,7,8]

// Now comes the main part. We can't extend any existing sequence with 4. So we need to create a new subsequence following 4th step previous approach but this time we will create it inside sub itself by replacing smallest element larger than 4 (Similar to 4th step above where we formed a new sequence after picking smaller elements than 4 from existing sequence).

//     [1,    4,      8]
//            ^sub2   ^sub1

// This replacement technique works because replaced elements dont matter to us
// We only used end elements of existing lists to check if they can be extended otherwise form newer lists
// And since we have replaced a bigger element with smaller one it wont affect the 
// step of creating new list after taking some part of existing list (see step 4 in above approach)
