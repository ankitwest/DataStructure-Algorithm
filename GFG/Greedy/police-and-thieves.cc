class Solution{
      public:
        int catchThieves(char arr[], int n, int k) {
        vector<int> p; vector<int> t;
        for(int i=0;i<n;i++){
            if(arr[i]=='P') p.push_back(i);
            else t.push_back(i);
        }
  int i=0,j=0,ans=0;
  while(i<p.size() and j<t.size()){
      if(abs(p[i]-t[j])<=k)
         ans++,i++,j++;
      else if(p[i]<t[j])
         i++;
      else
         j++;
  }
  return ans;
}
};
