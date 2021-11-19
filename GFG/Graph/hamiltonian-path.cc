class Solution{
public:
    bool backTrack(int node,int N,int ctr,vector<int> adj[],vector<int> &vis){
        if(ctr==N) return true;
        vis[node]=1;
        ctr++;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(backTrack(x,N,ctr,adj,vis)) return true;
            }
        }
        vis[node]=0;
        return false;
        
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int>adj[N+1];
        for(auto e:Edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(N+1);
        int count =0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                if(backTrack(i,N,1,adj,vis)) return true;
            }
        }
        return false;
    }
};
