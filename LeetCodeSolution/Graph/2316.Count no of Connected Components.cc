2316. Count Unreachable Pairs of Nodes in an Undirected Graph

//bfs  //dfs
class Solution1 {
public:
      long long bfs(vector<int> adj[], int node, vector<int> &vis){
        long long cnt = 0;
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(q.size()!=0){
            int node = q.front(); q.pop();
            cnt++;
            for(auto ch : adj[node]){
                if(!vis[ch]){
                    vis[ch] = 1;
                    q.push(ch);
                }
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            auto v = edges[i];
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        auto dfs = [&](auto dfs,int u,int par)->long long{
            vis[u] = 1;
            long long cnt = 1;
            for(auto child : adj[u]){
                if(child==par) continue;
                if(!vis[child])
                    cnt += dfs(dfs,child,u);
            }
            return cnt;
        };
        long long ans = 0; long long sum = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long cnt = dfs(dfs,i,-1);
                // long long cnt2 = bfs(adj,i,vis); //vis array
                ans += cnt*sum;
                sum += cnt;
            }
        }
        return ans;
    }
};

// int ans = n*(n-1)/2; // ans -= cnt*(cnt-1)/2;

// a*b + b*c + c*a
// a*(b+c) + b*c + c*0;

class DSU
{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
    }
    
    int find_par(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=find_par(parent[node]);
    }
    
    void _union(int u,int v)
    {
        int a = find_par(u);
        int b = find_par(v);
        if(a == b)
            return;
        
        if(size[a] < size[b]){
            size[b] += size[a];
            parent[a] = b;
        }else{
            size[a] += size[b];
            parent[b] = a;   
        }
    }
};
// with dsu class
class Solution22 {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(int i=0;i<edges.size();i++){
            auto v = edges[i];
            dsu._union(v[0],v[1]);
        }
        set<int> s;
        for(int i=0;i<n;i++)  s.insert(dsu.find_par(i));
        vector<int> v;
        for(auto i:s) v.push_back(dsu.size[i]);
        
        long long ans = 0; long long sum = 0;
        for(auto x:v){
            ans += x*sum;
            sum += x;
        }
        return ans;
    }
};

class Solution{
public:
     vector<int> parent;
     vector<int> size;
    void set_default(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_par(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_par(parent[node]);
    }
    void _union(int u,int v){
        int a = find_par(u);
        int b = find_par(v);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        set_default(n);
      
        unordered_map<int,int> mp;
        for(auto edge : edges){
            _union(edge[0],edge[1]); 
        }
        for(int i=0;i<n;++i){
            mp[find_par(i)]++;  //size
        }
        if(mp.size()==1) return 0;
        long long ans=0;
        for(auto [x,y] : mp){
            ans+=y*(n-y);
        }
        return ans/2;
    }
};
