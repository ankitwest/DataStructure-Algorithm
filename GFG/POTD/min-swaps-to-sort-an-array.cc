int minSwaps(vector<int>&arr)
	{
	    vector<pair<int,int>> v;
	    int n = arr.size();
	   for(int i=0;i<n;i++){
	       v.push_back({arr[i],i});
	   }
	   sort(v.begin(),v.end());
	   int ctr=0;
	   for(int i=0;i<n;i++){
	       if(v[i].second==i) continue;
	       swap(v[i],v[v[i].second]);
	       ctr++;i--;
	   }
	   return ctr;
	}
Expected Time Complexity: O(nlogn)
