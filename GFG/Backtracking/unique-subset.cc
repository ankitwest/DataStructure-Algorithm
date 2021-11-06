class Solution{
  public:
    void generateSubset(vector<int> &arr, int n,vector<int> &subset,set<vector<int>> &s,int i){
        
        if(i==n){
            s.insert(subset);
            return ;
        }
        //ith element not in subset
        generateSubset(arr,n,subset,s,i+1);
        
        //ith element is taken in subset
        subset.push_back(arr[i]);
        generateSubset(arr,n,subset,s,i+1);
        subset.pop_back();
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        vector<int> subset;
        set<vector<int>> s;
        vector<vector<int>> ans;
        generateSubset(arr,n,subset,s,0);
        ans.assign(s.begin(),s.end());
        return ans;
    }
};
Expected Time Complexity: O(2N).
