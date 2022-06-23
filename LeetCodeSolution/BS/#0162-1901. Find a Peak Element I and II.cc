
// 162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return n-1;
        
        int l = 1;int h = n-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1])
                return mid;
            if(nums[mid]<nums[mid+1])
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
  
  

// 1901. Find a Peak Element II


class Solution {
public: //  TC - M*log(N)
    int findMax(vector<int> arr){
        return (max_element(arr.begin(),arr.end()) - arr.begin());
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        int l = 0, h = n-1;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            int maxIdx = findMax(mat[mid]);
            if((mid==0 or mat[mid][maxIdx] > mat[mid-1][maxIdx]) and (mid==n-1 or mat[mid][maxIdx] > mat[mid+1][maxIdx]))
                return {mid,maxIdx};
            if(mat[mid][maxIdx] < mat[mid+1][maxIdx])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return {-1,-1};
    }
};

Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
