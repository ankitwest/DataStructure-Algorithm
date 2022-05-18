

// all 3 correct
class Solution1 {
public:
    vector<vector<vector<double>>> dp;
    double knight(int i,int j,int k,int n){
        if(i<0 or j<0 or i>=n or j>=n) return 0;
        if(k==0) return 1;
        
        if(dp[k][i][j]!=-1) 
            return dp[k][i][j];
        
        double sum = 0.0;
        sum += knight(i+2,j+1,k-1,n) + knight(i+2,j-1,k-1,n)+
                knight(i-2,j+1,k-1,n) + knight(i-2,j-1,k-1,n)+
                knight(i+1,j+2,k-1,n) + knight(i-1,j+2,k-1,n)+
                knight(i+1,j-2,k-1,n) + knight(i-1,j-2,k-1,n);
        
        double prob = sum/8.0;
        
        return dp[k][i][j] = prob;
    }
     double knightProbability(int N,int step,int start_x, int start_y)
	{
	     dp.resize(step+1,vector<vector<double>>(N+1,vector<double>(N+1,-1)));
	     return knight(start_x,start_y,step,N);
	}
};


class Solution {
 	public:
 	int dirs[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
 	 double knightProbability(int N,int step,int start_x, int start_y)
     {
        vector<vector<vector<double>>> dp(step+1,vector<vector<double>>(N+1,vector<double>(N+1,0.0)));
        dp[0][start_x][start_y] = 1;
        
        for(int k=1;k<=step;k++){
            for(int x=0;x<N;x++){
                for(int y=0;y<N;y++){
                    for(auto dir:dirs){
                      int nx=x+dir[0]; int ny=y+dir[1];
                       if(nx>=0 && nx<N && ny>=0 && ny<N){
                          dp[k][nx][ny]+=dp[k-1][x][y]/8.0;
                      }
                  }
                }
            }
        }
        
        double ans = 0.0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans += dp[step][i][j];
            }
        }
        return ans;
    }
};
class Solution3 {
	public:
	int dirs[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
	 double knightProbability(int N,int steps,int start_x, int start_y)
     {
	    vector<vector<double>> dp(N, vector<double>(N, 0.0));
	    dp[start_x][start_y] = 1.0;
	    
	    while(steps--) {
	        vector<vector<double>> ndp(N, vector<double>(N, 0.0));
	        for(int x = 0; x < N; x++) {
	            for(int y = 0; y < N; y++) {
    	            for(auto dir:dirs) {
    	                int nx = x + dir[0];
    	                int ny = y + dir[1];
    	                
    	                if(nx >= 0 && ny >= 0 && nx < N && ny < N) 
    	                    ndp[nx][ny] += dp[x][y] / 8;
    	            }
	            }
	        }
	        
	        dp = ndp;
	    }
	    
	    double ans = 0.0;
	    for(auto it: dp) ans += accumulate(it.begin(), it.end(), 0.0);
	    
	    return ans;
	}
};
