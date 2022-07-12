class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size(); 
        int cnt = 0; int ans = 0;
        int l = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) cnt++;
            
            while(l<n and cnt>k){
                if(arr[l]==0) cnt--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};

