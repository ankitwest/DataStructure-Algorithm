//TLE

class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int find_par(int node){
        if(node==parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void UNION(int u,int v){
        // int u = find_par(u);
        // int v = find_par(v);
            parent[v] = u;
        
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n);
        vector<bool> ans;
        
        for(auto request:requests){
            int u = request[0]; int v = request[1];
            int parU = dsu.find_par(u); int parV = dsu.find_par(v);
            
            bool flag = true;
            // Check if current friend request is restricted or not
            for(auto rest: restrictions){
                int a = rest[0]; int b = rest[1];
                int parA = dsu.find_par(a); int parB = dsu.find_par(b);

                if((parU==parA and parV==parB) or (parU==parB and parV==parA)) {
                    flag = false;
                    break;
                }
            }
             if(flag)
                dsu.UNION(parU,parV);  // Union u and v by passing parents // otherwise TLE
            
            ans.push_back(flag);
        }
        return ans;
    }
};
