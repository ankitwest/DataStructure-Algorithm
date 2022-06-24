class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0]; int high = matrix[n-1][n-1];
        int ans=0;
        
        // finding the rank of the number
        auto check22 = [&](int mid){
            int cnt = 0;
            for(int i=0;i<n;i++){
                cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            // cout<<mid<<" "<<cnt<<" "<<endl;
            return cnt;
        };
        
         auto check = [&](int mid){
            int cnt = 0; int j = n-1;
            for(int i=0;i<n;i++){
                while(j>=0 and matrix[i][j]>mid)
                    j--;
                cnt += (j+1);
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

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise


// [[1,3,7],[5,10,12],[6,10,15]]
// 5
