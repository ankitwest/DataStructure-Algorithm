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


struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};
