2 Jan 2022

class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
     vector<int> v(n);
     for(int i=0;i<n;i++){
         if(edge[i]!=-1)
          v[edge[i]]+=i;
     }
     int ans=n-1; int maxi=0;
     
     for(int i=n-1;i>=0;i--){
         if(v[i]>maxi) maxi = v[i],ans=i;
     }
     return ans;
  }
};
