class Solution{
  public:
  bool ans=false;

  void solve(int a[],int n,int curr,int cnt,int sum,int k,vector<bool> &vis){
      if(cnt==k-1){
          ans = true;
          return;
      }
      if(curr>sum)
        return;
        
      if(curr==sum)
        return solve(a,n,0,cnt+1,sum,k,vis);
    
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            solve(a,n,curr+a[i],cnt,sum,k,vis);
            vis[i] = false;
        }
    }
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if(k>n) return false;
        if(k==1) return true;
        
        int sum = accumulate(a,a+n,0);
        if(sum%k!=0) return false;
        
        vector<bool> vis(n,false);
        solve(a,n,0,0,sum/k,k,vis);
        return ans;
    }
};

Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), 
(1, 5), (6)
