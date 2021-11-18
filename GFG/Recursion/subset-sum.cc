class Solution{
public:
    void subset(int sum,vector<int>& arr,int N,vector<int>& ans,int ind){
        if(ind==N){
            ans.push_back(sum);
            return ;
        }
        
        subset(sum+arr[ind],arr,N,ans,ind+1);
        subset(sum,arr,N,ans,ind+1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subset(0,arr,N,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
Expected Time Complexity: O(2N)
