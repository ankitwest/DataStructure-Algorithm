class Solution {
public:  //dfs
    vector<int> vis,col;
   bool dfs(int node,int color, vector<vector<int>> &graph){
        vis[node]=1;
        col[node]=color;
        
        for(auto child:graph[node]){
            if(!vis[child]){
                if(dfs(child,color^1,graph)==false)
                    return false;
            }
            else{
                if(col[node]==col[child])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n);
        col.resize(n);
        
        for(int i=0;i<n;i++){
            if(!vis[i] and dfs(i,0,graph)==false)
                return false;
        }
        return true;
    }
};


//bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> col(n,0);
        for(int i=0;i<n;i++){
            if(col[i]==0){
                queue<int> q;
                q.push(i);
                col[i]=1;
                while(!q.empty()){
                    int curr= q.front();
                    q.pop();
                    for(auto neigh:graph[curr]){
                        if(col[neigh]==0) { //using it like not visited array
                            col[neigh]=-col[curr];
                            q.push(neigh);
                        }
                        else if(col[neigh]==col[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

