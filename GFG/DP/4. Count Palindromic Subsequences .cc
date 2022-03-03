




class Solution{
public:
    /*You are required to complete below method */
    vector<vector<long long>> dp;
      long long int mod=1e9+7;
    long long rec(string str,long long i,long long j){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        long long ans = 0;
        if(str[i]==str[j])
            ans = (1+rec(str,i+1,j)%mod+rec(str,i,j-1)%mod)%mod;
        else
            ans = (rec(str,i+1,j)%mod+rec(str,i,j-1)%mod-rec(str,i+1,j-1)%mod)%mod;
          
          if(ans<0) ans+=mod; 
        return dp[i][j] = ans;
    }
    long long int  countPS(string str)
    {
        long long n = str.size();
        dp.resize(n+1,vector<long long>(n+1,-1));
      return (rec(str,0,n-1))%mod;
    }
};



// Bottom Up 

class Solution{
public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
         long long int mod=1e9+7;
        int n=str.length();
         long long int dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){  // i==j
                    dp[i][j]=1;
                }
                else if(gap==1){
                    dp[i][j]=str[i]==str[j]?3:2;   // ab  // cc
                }
                else{
                    if(str[i]==str[j]){
                        dp[i][j]=(dp[i][j-1]%mod+(dp[i+1][j]%mod+1)%mod)%mod;
                    }
                    else{
                        dp[i][j]=(dp[i][j-1]%mod+dp[i+1][j]%mod-dp[i+1][j-1]%mod)%mod;
                    }
                    if (dp[i][j] < 0) dp[i][j] += mod;
                }
            }
        }
        return dp[0][n-1]%mod;
    }
};

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"

     
