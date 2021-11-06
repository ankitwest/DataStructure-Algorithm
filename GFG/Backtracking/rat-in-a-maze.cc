
class Solution{
  public:
    void dfs(int x,int y,string s,vector<string> &v,vector<vector<int>> &m,int n,vector<vector<int>> &vis){
        if(x<0 or y<0 or x>=n or y>=n or m[x][y]==0) return ;
        if(vis[x][y]==1) return ;
        
        if(x==n-1 and y==n-1){
            v.push_back(s);
            return ;
        }
        
        vis[x][y]=1;
        
        dfs(x+1,y,s+'D',v,m,n,vis);
        dfs(x-1,y,s+'U',v,m,n,vis);
        dfs(x,y+1,s+'R',v,m,n,vis);
        dfs(x,y-1,s+'L',v,m,n,vis);

        vis[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        if(m[0][0]==0) return v;
        if(m[n-1][n-1]==0) return v;
        
        string s ="";

        dfs(0,0,s,v,m,n,vis);
        sort(v.begin(),v.end());
        return v;
    }
};

Expected Time Complexity: O((3N^2)).
 Expected Time Complexity:O((N^2)^4). this maybe
