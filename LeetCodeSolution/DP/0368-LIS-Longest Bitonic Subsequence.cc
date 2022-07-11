GFG

class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n = arr.size();
	    vector<int> dp_left(n,1); vector<int> dp_right(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] and dp_left[j] + 1 > dp_left[i])
                    dp_left[i] = 1 + dp_left[j];
                // if(arr[i]>arr[j])    
                    // dp_left[i] = max(dp_left[i], 1 + dp_left[j]);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>arr[j] and dp_right[j] + 1 > dp_right[i])
                    dp_right[i] = 1 + dp_right[j];
                // if(arr[i]>arr[j])    
                    // dp_right[i] = max(dp_right[i], 1 + dp_right[j]);
            }
        }

        // for(int i=0;i<n;i++) cout<<dp_left[i]<<" "; cout<<endl;
        // for(int i=0;i<n;i++) cout<<dp_right[i]<<" "; cout<<endl;
        
        // int ans = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp_left[i] + dp_right[i] - 1);
        }
        return ans;
	}
};
