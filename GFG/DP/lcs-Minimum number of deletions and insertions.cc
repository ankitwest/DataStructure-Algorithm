class  Solution{
vector<vector<int>> dp;
	public:
	int solve(string s1,int i,string s2,int j){
	    if(i<0 and j<0) return 0;
	    if(i<0) return 0;
	    if(j<0) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    int ans = 0;
	    if(s1[i]==s2[j])
	        ans = 1 + solve(s1,i-1,s2,j-1);
	   else
	        ans = max(solve(s1,i-1,s2,j), solve(s1,i,s2,j-1));
	       
	   return dp[i][j] = ans;
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size(); int m = str2.size();
	    dp.resize(n,vector<int>(m,-1));
	    
	    int x = solve(str1,n-1,str2,m-1);
	    return n + m - 2*x;
	} 
  };
