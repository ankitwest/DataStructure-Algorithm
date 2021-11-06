class Solution {
public:
    void solve(vector<int>& A, int target,int sum,vector<int> &v,vector<vector<int>> &ans,int index){
        if(index==A.size() or sum>target) return;
        
        if(sum==target){
            ans.push_back(v);
            return;
        }
            sum += A[index];
            v.push_back(A[index]);
            solve(A,target,sum,v,ans,index);
            sum -= A[index];
            v.pop_back();

        solve(A,target,sum,v,ans,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(A,target,0,v,ans,0);
        return ans;
    }
};

class Solution{
    public:
    //Function to return a list of indexes denoting the required combinations whose sum is equal to given number.
    void solve(vector<int> &A,int sum,vector<int> &v,vector<vector<int>> &ans,int index){
        if(index==A.size()) return ;
    
        if(sum<0) return;
        if(sum==0) {
            ans.push_back(v); return;
        }
        if(A[index]<=sum){
            v.push_back(A[index]);
            solve(A,sum-A[index],v,ans,index);
            v.pop_back();
        }

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



Combination Sum 2

class Solution{
    public:
    void solve(vector<int> &A, int N, int target,int sum,vector<int> &v,set<vector<int>> &s,int index){
        if(sum==target) {
            s.insert(v);
            return ;
        }
        
        if(index==N or sum>target) return ;
        
        
            sum += A[index];
            v.push_back(A[index]);
            solve(A,N,target,sum,v,s,index+1);
            sum -= A[index];
            v.pop_back();

        
        solve(A,N,target,sum,v,s,index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){

      set<vector<int>> s;
      vector<int> v;
      sort(A.begin(),A.end());
      solve(A,N,B,0,v,s,0);
      vector<vector<int>> ans(s.begin(),s.end());

      return ans;
    }
};







leetcode
class Solution {
public:
    void helper(int index, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds){
        //base case
        //when the combination ds is carrying is a valid one add it into th ans
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i< candidates.size(); i++){
            if(candidates[i] > target) break; // no point of it to add it to the ans if the  candidate at ith element exceeds the target no picking up hence break 
            if(i  > index && candidates[i] == candidates[i-1])
                continue;
                //to avoid picking up the same elements and thus avoiding duplicates (no picking of element)
            ds.push_back(candidates[i]);
            helper(i+1, target- candidates[i], candidates, ans, ds); //call for next  index element
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort the given candidates vector 
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};

