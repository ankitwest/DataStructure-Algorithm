class Solution{
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<int,vector<int>,greater<int>> minpq;
      
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                minpq.push(arr[i][j]);
            }
        }
        vector<int> ans;
        while(!minpq.empty()){
            ans.push_back(minpq.top());
            minpq.pop();
        }
        return ans;
    }
};

Expected Time Complexity: O(K2*Log(K))
Expected Auxiliary Space: O(K)
