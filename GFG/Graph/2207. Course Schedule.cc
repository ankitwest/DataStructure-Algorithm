class Solution {
public:   // topological sorting  //bfs  //kahn' algo
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }
        
        queue<int> q;
         for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
         }

        vector<int> topoSort;
        
         while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front(); q.pop();
                topoSort.push_back(curr);
                for(auto child: adj[curr]){
                    indeg[child]--;
                    if(indeg[child]==0)
                        q.push(child);
                }
            }
        }
        return (topoSort.size()==n);
    }
};
    
    
//dfs  // it will not work ,
//it will give topoSortng even in cyclic graph
class SolutionWA {
public:   
    void findTopoSort(vector<int> adj[],vector<int>& vis,int node,int par,stack<int> &st){
        vis[node] = 1;
        for(auto child: adj[node]){
            // if(child==par) continue;  //  remove this one in directed graph
            if(!vis[child])
               findTopoSort(adj,vis,child,node,st);
        }
        st.push(node);
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                findTopoSort(adj,vis,0,-1,st);
            }
        }
        vector<int> topoSort;
        while(!st.empty()){
            int x = st.top();st.pop();
            topoSort.push_back(x);
        }
        
        return (topoSort.size()==n);
    }
};

//cycle in DG 
class Solution {
public:   
    bool dfsCycle(vector<int> adj[],vector<int>& vis,int node,int par,vector<int>& anc){
        vis[node] = 1;
        anc[node] = 1;
        for(auto child: adj[node]){
            // if(child==par) continue; //  remove this one in directed graph
            if(!vis[child]){
                if(dfsCycle(adj,vis,child,node,anc)) return true;
            }
            else if(anc[child] == 1){
                return true;
            }
        }
        anc[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        vector<int> anc(n,0);
        bool flag = false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfsCycle(adj,vis,i,-1,anc)) flag = true;
            }
        }
        if(flag) return false;
        return true;
    }
};

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
