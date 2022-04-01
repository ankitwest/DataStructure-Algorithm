


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        long long ans = -1;  vector<int> res={-1,-1,-1};
         
        vector<int> maxi(n,0);  maxi[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--) maxi[i] = max(maxi[i+1],arr[i]);
        
        set<int> s;
        for(int i=1;i<n-1;i++){
            s.insert(arr[i-1]);
            auto itr = s.lower_bound(arr[i]);
            if(itr!=s.begin() and maxi[i+1]>arr[i]){
                itr--;
                long long curr = 1ll*(*itr)*(arr[i])*(maxi[i+1]);
                if(curr>ans)
                    ans = curr,res = {*itr,arr[i],maxi[i+1]};
            }
        }
        return res;
    } 
};


n = 8
arr[ ] = {6, 7, 8, 1, 2, 3, 9, 10}
Output:
8 9 10
