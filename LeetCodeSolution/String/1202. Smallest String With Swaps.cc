class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size(); 
        
        vector<int> adj[n];
        for(auto pair:pairs){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        vector<bool> vis(n,false);
        auto dfs = [&](const auto &dfs,int node,vector<int> &curr_comp)->void{
            vis[node] = true;
            curr_comp.push_back(node);
            
             for(auto neigh : adj[node]){
                if(!vis[neigh])
                    dfs(dfs, neigh, curr_comp);
            }
        };
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> curr_comp;
                dfs(dfs,i,curr_comp);
                
                vector<char> v;
                for(auto i:curr_comp)
                    v.push_back(s[i]);
                
                sort(curr_comp.begin(),curr_comp.end());
                sort(v.begin(),v.end());
                
                for(int i = 0; i < curr_comp.size(); i++) {   
                    s[curr_comp[i]] = v[i];
                }
            }
        }
        return s;
    }
};
