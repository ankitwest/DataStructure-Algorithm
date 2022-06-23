class Solution {
public:   //similar to word ladder ii path find
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,int node,int par,vector<int> v){
        v.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(v);
            return ;
        }
        for(auto child:graph[node]){
            dfs(graph,child,node,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v;
        
        dfs(graph,0,-1,v);
        return ans;
    }
};
