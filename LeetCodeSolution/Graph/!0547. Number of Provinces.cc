class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int src){
        vis[src] = 1;
        for(auto it:adj[src]){
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    int findCircleNum(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
            
        
        vector<int> adj[n];
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1)
                    adj[i].push_back(j);
            }
        }
        
        int groups=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                groups++;
                dfs(adj,vis,i);
            }
        }
        return groups;
    }
};
// with auto fxn
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size();int m=isConn[0].size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j) continue;
                if(isConn[i][j]==1) adj[i].push_back(j);
            }
        }
        
        bool vis[n];
        memset(vis,false,sizeof(vis));
        
        auto dfs = [&](const auto& dfs,int node,int par)-> void{
            vis[node] = true;
            for(auto child:adj[node]){
                if(child==par) continue;
                if(!vis[child])
                    dfs(dfs,child,node);
            }
        };
        
        int province = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                province++;
                dfs(dfs,i,-1);
            }
        }
        return province;
    }
};



Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2  
    
    
    
    
    Unionn Find
    class Solution {
public:
    int parent[201];
    void make_set(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    void UNION(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a!=b){
            parent[b]=a;
        }
    }
    int find_parent(int node){
        if(node==parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }
    
    int findCircleNum(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
            
        make_set(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1)
                    UNION(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                ans++;
        }
        return ans;
    }
};
