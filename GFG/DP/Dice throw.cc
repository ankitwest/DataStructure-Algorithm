 public:
  vector<vector<long long>> dp;

  long long solve(int x,int n,int m){
      if(x<0) return 0;
      if(n==0 and x==0) return 1;
      if(n==0 and x>0) return 0;
     
      
      if(dp[x][n]!=-1)
      return dp[x][n];
      
      long long ans = 0;
      for(int i=1;i<=m;i++){
          ans += solve(x-i,n-1,m);
      }
      return dp[x][n] = ans;
  }
    long long noOfWays(int M , int N , int X) {
        dp.resize(X+1,vector<long long> (N+1,-1));
        return solve(X,N,M);
    }



Ndice
Mface
Xvalue
