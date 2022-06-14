

class Solution {
public:
    // TC : O(n * n * 2^n)     { maxn = 12 }
    
// Every node can have 2^n state because of mask and total number of nodes are n, therefore in worst case we will push n * 2^n states in queue and pop them.
// now for every state we will try to check it neighbors and see if we can push them.
// A node can have O(n) neighbors.
    
    struct tuple{
        int node;
        int mask;
        int cost;
        tuple(int node,int mask,int cost){
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // queue<array<int,3>> q;
        queue<tuple> q;
        set<pair<int,int>> vis;
        int all = (1<<n)-1;
        for(int i=0;i<n;i++){
            tuple x(i,1<<i,0);
            q.push(x);
            vis.insert({i,1<<i});
        }
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr.mask==all) return curr.cost;
            
            for(auto child : graph[curr.node]){
                int bothVisMask = curr.mask | (1<<child) ;
                tuple x(child,bothVisMask,curr.cost+1);
                
                if(vis.find({child,bothVisMask})!=vis.end()) continue;
                vis.insert({child,bothVisMask});
                q.push(x);
            }
        }
        return -1;
    }
};

Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
