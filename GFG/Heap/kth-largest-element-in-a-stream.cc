class Solution{
public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>>minpq;
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(minpq.size()<k)
                minpq.push(arr[i]);
            else{
                if(arr[i]>minpq.top())
                { minpq.pop();  minpq.push(arr[i]); }
            }
            if(minpq.size()<k)
                ans[i] = -1;
            else
               ans[i] = minpq.top();
        }
          return ans;
    }
};


Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n)
