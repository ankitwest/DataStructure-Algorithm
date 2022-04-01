long long maxProduct(vector<int> arr, int n) {
	    long long l = 1,r = 1;  long long  ans = INT_MIN;
	    
	    for(int i=0;i<n;i++){   // -8,2,4
	        l*=arr[i];
	        r*=arr[n-1-i];
	        ans = max(ans,max(l,r));
	        if(l==0) l=1;
	        if(r==0) r=1; 
	    }
  return ans;
  
  
  
  M-2
    
  long long maxProd = 1, minProd = 1, ans = INT_MIN;
	    for(int i=0;i<n;i++){ 
	        if(arr[i]<0)
	            swap(maxProd,minProd);
	       maxProd = max(maxProd*arr[i],(long long)arr[i]);
	       minProd = min(minProd*arr[i],(long long)arr[i]);
	       //cout<<maxProd<<" "<<minProd<<endl;
	       ans = max(ans,maxProd);
	    }
	    return ans;
