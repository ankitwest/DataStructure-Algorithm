class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       set<int> s;int ans=0;
        int prev=0;
       for(int i=0;i<arr.size();i++){
           s.insert(arr[i]);
           int ff = *s.begin();int ss = *s.rbegin();
           int sz = s.size()-1;
           if(prev==ff and ss-ff==sz){
               ans++;
               prev=ss+1;
               s.clear();
           }
       }
        return ans;
    }
};

M-2
  class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0; int maxi=0; int n = arr.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            if(maxi==i) cnt++;
        }
        return cnt;
    }
};
