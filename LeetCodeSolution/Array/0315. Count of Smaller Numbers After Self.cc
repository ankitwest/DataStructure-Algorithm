class Solution {
    vector<int> ans;
    void merge(vector<pair<int, int>> &a, int left, int mid, int right){
        vector<pair<int, int>> temp(right-left+1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid and j <= right) {
            // mind that we're sorting in descending order
            if (a[i].first <= a[j].first) { 
                temp[k++] = a[j++];
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                ans[a[i].second] += right - j + 1;
                temp[k++] = a[i++];
                
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= right) {
            temp[k++] = a[j++];
        }
        for (int i = left; i <= right; i++)
            a[i] = temp[i-left];
    }
    
    void merge_sort(vector<pair<int,int>>& v,int left,int right){
        if(left < right){
            int mid = left + (right-left)/2;
            merge_sort(v, left, mid);
            merge_sort(v, mid+1, right);
            merge(v, left, mid, right);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n,0);
        
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++){
            v[i] = {nums[i], i};
        }
        merge_sort(v, 0, n-1);
        
        return ans;
    }
};
