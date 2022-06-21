class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(); 
        if(n==1) return 1;
        int inc = 1; int dec = 1; int ans = 1;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                inc = dec + 1;
                dec = 1;
            }else if(arr[i-1] > arr[i]){
                dec = inc + 1;
                inc = 1;
            }else if(arr[i-1] == arr[i]){
                inc = 1;
                dec = 1;
            }
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
Example 2:

Input: arr = [4,8,12,16]
Output: 2
Example 3:

Input: arr = [100]
Output: 1
