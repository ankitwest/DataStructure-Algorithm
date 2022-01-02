#define ll long long 
class Solution {
public:
    bool inside(ll circle_x, ll circle_y, ll rad, ll x, ll y){
        if((circle_x-x)*(circle_x-x)+(circle_y-y)*(circle_y-y) <= rad*rad) return true;
        else return false;
    }
    int bfs(int i,vector<int> adj[],int n){
        vector<int> vis(n,0);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int ctr=1;
        while(!q.empty()){
            int curr = q.front();q.pop();
            
            for(auto child:adj[curr]){
                if(!vis[child]){
                    q.push(child);
                    vis[child]=1;
                    ctr++;
                }
            }
        }
        return ctr;
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            int circle_x = bombs[i][0];
            int circle_y = bombs[i][1];
            int rad = bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x = bombs[j][0];
                int y = bombs[j][1];
                if(inside(circle_x, circle_y, rad, x, y)) adj[i].push_back(j);
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,bfs(i,adj,n));
        }
        return maxi;
    }
};
