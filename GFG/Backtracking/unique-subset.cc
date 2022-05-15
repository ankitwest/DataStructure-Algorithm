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

  
  
  
  
class Solution
{
    public:
    vector<vector<int>> ans;
    void generateSubsets(int idx,vector<int> &arr,int n,vector<int> &temp){
        ans.push_back(temp); 
        
        for(int i=idx;i<n;i++){
            if(i!=idx and arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            generateSubsets(i+1,arr,n,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> AllSubsets(vector<int> arr,int n){
        sort(arr.begin(),arr.end());
        vector<int> temp;
        generateSubsets(0,arr,n,temp);
        return ans;
    }
};
