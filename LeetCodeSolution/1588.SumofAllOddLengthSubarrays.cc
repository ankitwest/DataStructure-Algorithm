class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int pre[n+1];
        pre[0]=0;
        pre[1]=arr[0];
        
          for(int i=2;i<=n;i++)
              pre[i]=pre[i-1]+arr[i-1];
          
        
        int ans=0;int a=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j+=2){
                a = pre[j+1]-pre[i];
                ans += a;
            }
        }
        return ans;
    }
};

class Solution {
public:
 int sumOddLengthSubarrays(vector<int>& arr) {
     int n=arr.size(); int ans=0;
     for(int i=0;i<n;i++){
         int contri = ceil((i+1)*(n-i)/2.0);
         ans += contri*arr[i];
         }
     return ans;
     }
};
