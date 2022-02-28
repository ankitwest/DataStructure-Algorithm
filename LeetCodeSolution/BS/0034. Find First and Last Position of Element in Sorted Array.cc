class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        // int x = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // int y = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        // if(x<y)  return {x,y-1};
        // return {-1,-1};
        
        auto find = [&](int target){
            int low = 0; int high = arr.size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(arr[mid]<target) low = mid+1;
                else high = mid-1;
            }
            return low;
        };
        int posleft = find(target);
        int posright = find(target+1);
        if(posleft==arr.size() or arr[posleft]!=target) return {-1,-1};
        return {posleft,posright-1};
    }
};

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
