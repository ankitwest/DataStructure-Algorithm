class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        const long long int mod = 1e9+7;
        long long int ans=0; 
        for(int bit=0;bit<32;bit++){
            long long int ctr=0;
            for(int i=0;i<n;i++){
                if(arr[i]&(1<<bit)) ctr++;
            }
            ans += 2*ctr*(n-ctr);
            ans %=mod;
        }
        return ans;
    }
};
Expected Time Complexity: O(N * log2(Max(Ai)))
Input: N = 3
A = {1, 3, 5}
Output: 8
Explaination: We return 
f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) + 
f(5, 1) + f(5, 3) + f(5, 5) = 
0 + 1 + 1 + 
1 + 0 + 2 + 
1 + 2 + 0 = 8.
