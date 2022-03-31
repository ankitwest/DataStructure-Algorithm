
class Solution{
    public:
    int countOfNodes2(vector<int> graph[], int n)
    {
        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(1); vis[1]=true;
        int red=0; int black=0;
        
        int  level=0;
        while(!q.empty()){
            int sz=q.size();
            if(level%2==0) black+=sz;
            else red += sz;
            
            while(sz--){
                int u = q.front(); q.pop();
                for(int i=0;i<graph[u].size();i++){
                    int v = graph[u][i];
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            level++;
        }
        int ans = (red*(red-1))/2LL + (black*(black-1))/2LL;
        return ans;
    }
    int countOfNodes3(vector<int> graph[], int n)
    {
        vector<bool> vis(n+1,false);
        vector<int > dist(n+1,0);
        queue<int> q;
        q.push(1); vis[1]=true; dist[1]=0;
        int red=0; int black=0;
        
         while(!q.empty()){
             int u = q.front(); q.pop();
                for(int i=0;i<graph[u].size();i++){
                    int v = graph[u][i];
                    if(!vis[v]){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        vis[v] = true;
                    }
                }
         }
         
         for(int i=1;i<dist.size();i++){
             if(dist[i]%2==0) black++;
             else red++;
         }
         int ans = (red*(red-1))/2LL + (black*(black-1))/2LL;
        return ans;
    }
    
    
    void dfs(int u,int par,int d,vector<int> graph[],vector<int> &dp){
         dp[d]++;
            for(int i=0;i<graph[u].size();i++){
                if(graph[u][i]!=par){
                    dfs(graph[u][i],u,d^1,graph,dp);
                }
        }
    }
    int countOfNodes(vector<int> graph[], int n)
    {
        vector<int> dp(2,0);
        dfs(1,-1,0,graph,dp);
        
        int ans = (dp[0]*(dp[0]-1))/2LL + (dp[1]*(dp[1]-1))/2LL;
        return ans;
    }
       
};
