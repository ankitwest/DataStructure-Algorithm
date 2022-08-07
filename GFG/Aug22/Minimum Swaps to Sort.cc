class Solution 
{
    public:
	int minSwaps(vector<int>& arr)
	{
	    vector<pair<int,int>> vp;
	    int n = arr.size();
	   for(int i=0;i<n;i++){
	       vp.push_back({arr[i],i});
	   }
	   sort(vp.begin(),vp.end());
	   
	   int ctr=0;
	   for(int i=0;i<n;i++){
	       if(v[i].second != i) {
	           swap(v[i],v[v[i].second]);
	           ctr++;
	           i--;
	       }
	   }
	   return ctr;
	}
};
