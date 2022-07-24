class Solution {
  public:
    int maxLength(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        
        unordered_map<int,int>mp;
        for(int sum=2; sum<=2*n; sum++){  //  N + N
            int l = 0 ;int r = n-1;
            while(r > l){
                if(a[l] + a[r] == sum){
                    mp[sum]++;
                    l++;
                    r--;
                }else if(a[l] + a[r] < sum){
                    l++;
                }else if(a[l] + a[r] > sum){
                    r--;
                }
            }
        }
        
        int maxi = 0;
        for(int sum=2; sum<=2*n; sum++){
            maxi = max(maxi,mp[sum]);
        }
        return maxi;
    }
};
