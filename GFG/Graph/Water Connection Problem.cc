

void dfs(int node, int start, vector<pair<int,int>> adj[], vector<vector<int>> &ans, int dia){
        if(adj[node].size() == 0){
            ans.push_back({start,node,dia});
            return;
        }
        for(auto ch: adj[node]){
            dfs(ch.first, start, adj, ans, min(dia, ch.second));
        }
        return;
    }
    
    
public:
    vector<vector<int>> solve(int n,int pp,vector<int> a,vector<int> b,vector<int> d)
    {
        set<int> s;
        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<pp; i++){
            adj[a[i]].push_back({b[i],d[i]});
            s.insert(a[i]);
        }
        for(int i=0; i<pp; i++)
            s.erase(b[i]);
            
        vector<vector<int>> ans;
        for(auto it:s){
            dfs(it,it,adj,ans,INT_MAX);
        }
        return ans;
    }
