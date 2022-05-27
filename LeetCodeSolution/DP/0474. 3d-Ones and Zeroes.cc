

// bottom down
class Solution2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]={0};
        map<string,array<int,2>> freq;
        for(auto s:strs){
             int z=0,o=0;
             for(char i:s)
                 if(i=='0') z++; else o++;
             freq[s] = {z,o};
        }
        for(int i=0;i<strs.size();i++){
            auto [z,o] = freq[strs[i]];
            
            for(int j=m;j>=z;j--){
                for(int k=n;k>=o;k--){
                    dp[j][k] = max(1 + dp[j-z][k-o] , dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};

// top down
class Solution {
public:
    int dp[601][101][101];
     map<string,array<int,2>> freq;
    
    int solve(int ind,int z,int o,vector<string>& strs,int m,int n){
        if(ind>=strs.size() or z>m or o>n) 
            return 0;
        
        if(dp[ind][z][o]!=-1) 
            return dp[ind][z][o];
        
        auto [zz,oo] = freq[strs[ind]]; 
        
        int ans = 0;
        if(z+zz<=m and o+oo<=n)
            ans = max(1 + solve(ind+1,z+zz,o+oo,strs,m,n) , solve(ind+1,z,o,strs,m,n));
        else 
            ans = solve(ind+1,z,o,strs,m,n);
        
        return dp[ind][z][o] = ans;
    }
     int findMaxForm(vector<string>& strs, int m, int n) {
         int sz = strs.size();
         memset(dp,-1,sizeof(dp));
         for(auto s:strs){
             int z=0,o=0;
             for(char i:s)
                 if(i=='0') z++; else o++;
             freq[s] = {z,o};
         }
         int z=0,o=0,ind=0;
         return solve(ind,z,o,strs,m,n);
     }
};
