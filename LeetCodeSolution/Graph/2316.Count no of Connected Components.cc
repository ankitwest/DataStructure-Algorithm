2316. Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution1 {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            auto v = edges[i];
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        auto dfs = [&](auto dfs,int u,int par,int &cnt)->void{
            vis[u] = 1;
            cnt++;
            for(auto child : adj[u]){
                if(child==par) continue;
                if(!vis[child])
                    dfs(dfs,child,u,cnt);
            }
        };
        long long ans = 0; long long sum = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt = 0;
                dfs(dfs,i,-1,cnt);
                ans += cnt*sum;
                sum += cnt;
            }
        }
        return ans;
    }
};


class Solution2 {
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
    vector<int>parent,size;
    DSU(int n)
    {
        for(int i=0;i<n;++i)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findparent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findparent(parent[node]);
    }
    
    void unionOf(int n1,int n2)
    {
        int up1=findparent(n1);
        int up2=findparent(n2);
        if(up1==up2)
            return;
        
        if(size[up1]<size[up2])
        {
            size[up2]+=size[up1];
            parent[up1]=up2;
        }
        else
        {
            size[up1]+=size[up2];
            parent[up2]=up1;   
        }
    }
};

class Solution3 {
public:
    // vector<int> parent;
    // vector<int> rank;
//     int find_par(int node){
//         if(node==parent[node])
//             return node;
//         return parent[node] = find_par(parent[node]);
//     }
//     void union1( int a, int b, int n) 
//     {
//         int i = find_par(a);
//         int j = find_par(b);
        
//          if (i != j) {
//             if (rank[i] < rank[j])
//                 swap(i, j);
//             parent[j] = i;
//             rank[i] += rank[j];
//         }
//     }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        // parent.resize(n,0);
        // rank.resize(n,0);
        // for(int i=0;i<n;i++){
        //     parent[i] = i;
        //     rank[i] = 1;
        // }
        DSU dsu(n);
        for(int i=0;i<edges.size();i++){
            auto v = edges[i];
            dsu.unionOf(v[0],v[1]);
        }
        //map is better
        set<int> s;
        for(int i=0;i<n;i++)  s.insert(dsu.findparent(i));
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
     int parent[100005];
    int size[100005];
    void make(int x){
        parent[x]=x;
        size[x]=1;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;++i){
            make(i);
        }
        unordered_map<int,int> mp;
        for(auto edge : edges){
            Union(edge[0],edge[1]);
        }
        for(int i=0;i<n;++i){
            mp[find(i)]++;
        }
        if(mp.size()==1) return 0;
        long long ans=0;
        for(auto val : mp){
            long long x=val.second;
            ans+=x*(n-x);
        }
        return ans/2;
    }
};





    
