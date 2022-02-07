class DSU{
    vector<int> parent;
    vector<long long> size;
public:
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_par(int node){
        if(node==parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void UNION(int a,int b){
        int u = find_par(a);
        int v = find_par(b);
        
        if(size[v]>size[u]){
            size[v] += size[u];
            parent[u] = v;
        }else {
            size[u] += size[v];
            parent[v] = u;
        }
    }
};

DSU dsu(n);

dsu.UNION(u,v);
