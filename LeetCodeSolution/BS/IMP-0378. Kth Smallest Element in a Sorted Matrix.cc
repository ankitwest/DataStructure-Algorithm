

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0]; int high = matrix[n-1][n-1];
        int ans=0;
        
        auto check = [&](int mid){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            return cnt;
        };
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid)>=k)
                ans=mid,high=mid-1;
            else 
                low = mid+1;
        }
        return ans;
    }
};

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
