

class Solution {
public:
    map<int,vector<int>> persons;
    int n;
    int dp[(1<<10)+1][41];
    const int mod = 1e9+7;
    int solve(int peopleMask,int idHat){
        if(peopleMask == ((1<<n)-1)) return 1;
        
        if(idHat == 41) return 0;
        
        if(dp[peopleMask][idHat]!=-1)
            return dp[peopleMask][idHat];
        
        int ans = 0;
        //not give hat
        ans = (ans%mod + solve(peopleMask,idHat+1)%mod)%mod;
        
        //give hat
        for(auto per : persons[idHat]){
            int mask = 1<<per;
            if((mask&peopleMask)==0){
                ans = (ans%mod + solve(mask|peopleMask,idHat+1)%mod)%mod;
            }
        }
        return dp[peopleMask][idHat] = ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<hats[i].size();j++){
                persons[hats[i][j]].push_back(i);
            }
        }
        
       return solve(0,1)%mod;  //solve(peopleMask,idHat);
    }
};

// hats = [[3,4],[4,5],[5]]
// person
// 3 - 0
// 4 - 0,1
// 5 - 1,2

// hats = [[3,5,1],[3,5]]
// person
// 1 - 0
// 3 - 0,1
// 5 - 0,1
