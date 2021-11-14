class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    const int mod = 1e9+7;
    int catalan_numbers(int n){
        long long catalan[n+1]={0};
        catalan[0]=catalan[1]=1;
        for(int i=2;i<=n;i++){
              int no =i;
            for(int j=0;j<i;j++)
                catalan[i] = (catalan[i]+(catalan[j]*catalan[no-1-j])%mod)%mod;
        }
        return (int)catalan[n];
    }
    int numTrees(int n) 
    {
      return catalan_numbers(n);
    }
};
Expected Time Complexity: O(N2).
