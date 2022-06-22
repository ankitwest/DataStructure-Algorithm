class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        auto quickSelect = [&](auto quickSelect,int low,int high)->int{
            int pivot = nums[high];
            int piv = low;
            
            for(int i=low;i<high;i++){
                if(nums[i] <= nums[high]){
                    swap(nums[piv++], nums[i]);
                }
            }
            
            swap(nums[piv], nums[high]);
            
            if(k < piv)  return quickSelect(quickSelect, low, piv-1);
            else if(k > piv) return quickSelect(quickSelect, piv+1, high);
            return nums[piv];
        };
        return quickSelect(quickSelect,0, nums.size()-1);
    }
};


//heap
 class Solution1 {
public:   // TC - O(NlogK)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
        int x = 0;
        while(k--){
             x = pq.top(); pq.pop();
        }
        return x;
    }
};



// change in value of k
// quick sort less than pivot , pivot , greater than pivot
class Solution {
private:
    int quickSelect(vector<int>& nums, int low, int high, int k) {
      int pivot_ind = low;

      for (int j = low; j < high; j++) {
        if (nums[j] <= nums[high]) {
            swap(nums[pivot_ind++],nums[j]);
        }
      }
        swap(nums[pivot_ind],nums[high]);

      int count = high - pivot_ind + 1;  // no greater than pivot
      if (count == k) return nums[pivot_ind];
      if (count > k) return quickSelect(nums, pivot_ind + 1, high, k);  //pivot is too small , go right
      return quickSelect(nums, low, pivot_ind - 1, k - count); // pivot is too big, go left
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};



Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

