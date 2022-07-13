class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        unordered_map<int,int>m;
        m[0] = 1; int ans = 0; int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(m.count(sum-k))
                ans += m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};


Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.
