

class Solution{
  public:  //TC - NlogN
    int minimumRooms(int n, vector<int> &start, vector<int> &end) {
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int cnt = 0;
        int i = 0;int j = 0;
        
        // for(int i=0;i<n;i++) cout<<start[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<end[i]<<" ";
        // cout<<endl;
        
        int maxi = 0;
        while(i<n and j<n){
            if(start[i] <= end[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxi = max(maxi,cnt);
        }
        
        return maxi;
    }
};


class Solution{
  public:  //TC - N
  //range update points query
    int minimumRooms(int n, vector<int> &start, vector<int> &end) {
        vector<int> freq(2361,0);
        
        for(int i=0;i<n;i++){
            freq[start[i]]++;
            freq[end[i] + 1]--;
        }
        
        vector<int> preSum(2361,0);
        preSum[0] = freq[0];
        int maxi = preSum[0];
        
        for(int i=1;i<2361;i++){
            preSum[i] = preSum[i-1] + freq[i];
            maxi = max(maxi, preSum[i]);
        }
        return maxi;
    }
};
