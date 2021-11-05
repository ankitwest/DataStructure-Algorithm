class Solution{
public:
    //Function to return a list of indexes denoting the required combinations whose sum is equal to given number.
    void solve(vector<int> &A,int sum,vector<int> &v,vector<vector<int>> &ans,int index){
        if(index==A.size()) return ;
    
        if(sum<0) return;
        if(sum==0) {
            ans.push_back(v); return;
        }

            v.push_back(A[index]);
            solve(A,sum-A[index],v,ans,index);
            v.pop_back();

        solve(A,sum,v,ans,index+1);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        
        solve(A,B,v,ans,0);
        return ans;
    }
};
