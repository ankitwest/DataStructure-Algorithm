Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
  
  
  

BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0]; int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> vis(n,0);
        
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(curr==end)
                return true;
            
            for(auto child:graph[curr]){
                if(!vis[child]){
                    q.push(child);
                    vis[child]=1;
                }
            }
        }
        return false;
    }
};




