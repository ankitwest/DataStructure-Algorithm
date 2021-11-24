class Solution{
  public:
    void dfs(vector<int> adj[],vector<int> &vis,int node){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]) 
                dfs(adj,vis,x);
        }
    }
    int isCircle(int N, vector<string> A){
        vector<int> adj[26];
        vector<int> in(26,0);
        vector<int> out(26,0);
        for(int i=0;i<N;i++){
            int ch1 = A[i][0]-'a';
            int ch2 = A[i].back()-'a';
            adj[ch1].push_back(ch2);
            out[ch1]++;
            in[ch2]++;
        }
        for(int i=0;i<26;i++){
            if(in[i]!=out[i]) return 0;
        }
        int src;
        for(int i=0;i<26;i++){
            if(out[i]){
                src=i; break;
            }
        }
        
        vector<int> vis(26,0);
        dfs(adj,vis,src);
        
        for(int i=0;i<26;i++){
            if(out[i] and !vis[i]) 
                return 0;
        }
        return 1;
    }
};
Expected Time Complexity: O(N)
