class Solution {
public:
    vector<int> par;
  
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    
    void merge(int x,int y){
        int a = find(x);
        int b = find(y);
        
        if(a!=b){
            par[b] = a;
        }
    }
    
    int solve(vector<vector<int>>& edges,int type){
        int edge = 0;
        for(int i=0;i<edges.size();i++){
            int t = edges[i][0];
            int u = edges[i][1]-1; int v = edges[i][2]-1;
            if(type==t and find(u)!=find(v)) {
                merge(u,v);
                edge++;
            }
        }
        return edge;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        
        int t3 = solve(edges,3);
        vector<int> par_copy = par;
        
        par = par_copy;   // after using t3 edge same parent
        int t1 = solve(edges,1);
        par = par_copy;   // after using t3 edge same parent
        int t2 = solve(edges,2);
        
        if((t1+t3)!=n-1 or (t2+t3)!=n-1)
            return -1;
        return m - t3 - t1 - t2;
    }
};
