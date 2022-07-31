
class Solution{
public:
    vector<vector<int>>dp;
    int solve(int n,int a[],int idx)
    {  
        if(n==0)
            return 0;
        
        if(idx==1)
           return n*a[idx-1];
        
     if(dp[n][idx]!=-1)
         return dp[n][idx];
         
     int take=0;
        if(n >= idx)
            take = a[idx-1]+solve(n-idx,a,idx);
       int nottake = solve(n,a,idx-1);
     
     return dp[n][idx] = max(take,nottake);
    }
    int cutRod(int price[], int n) {
        
         dp.resize(n+1,vector<int>(n+1,-1));
         
        int g = solve(n,price,n);
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     cout<<dp[i][j]<<" ";
            
        //     cout<<endl;
        // }
        return g;
    }
    };
