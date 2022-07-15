
class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
         int i=0,j=0,k=0;
        int size1=A.size();int size2=B.size();int size3=C.size();
        
        if(size1+size2!=size3) return false;
        
        vector<vector<bool>> dp(size1+1,vector<bool> (size2+1));
        for(int i=0;i<=size1;i++){
            for(int j=0;j<=size2;j++){
                if(i==0 and j==0) dp[i][j]=true;
                else if(i==0){
                     if(B[j-1]==C[i+j-1])
                         dp[i][j] = dp[i][j-1];
                }
                else if(j==0){
                     if(A[i-1]==C[i+j-1])
                         dp[i][j] = dp[i-1][j];
                }
                else {
                    if(A[i-1]==C[i+j-1] and B[j-1]!=C[i+j-1]) 
                        dp[i][j]=dp[i-1][j];
                    else if(A[i-1]!=C[i+j-1] and B[j-1]==C[i+j-1]) 
                        dp[i][j]=dp[i][j-1];
                    else if(A[i-1]==C[i+j-1] and B[j-1]==C[i+j-1]) 
                        dp[i][j]=dp[i][j-1] or dp[i-1][j];
                }
            }
        }
        return dp[size1][size2];
    }

};



class Solution2{
    int t[105][105];
    bool check(string s1,string s2,int i,int j,string s3){
        if(i==s1.size() and j==s2.size() and (i+j)==s3.size())
            return true;

        if(t[i][j]!=-1)
            return t[i][j];
            
        bool a = false, b = false;
        int k = i+j;
        if(s1[i]==s3[k])
          a = check(s1,s2,i+1,j,s3);
          
        if(s2[j]==s3[k])
          b = check(s1,s2,i,j+1,s3);
          
         return t[i][j] = a | b;
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.size(); int m = B.size(); int k = C.size();
        memset(t,-1,sizeof(t));
        if(n + m != k) 
            return false;
        return check(A,B,0,0,C);
    }
};
