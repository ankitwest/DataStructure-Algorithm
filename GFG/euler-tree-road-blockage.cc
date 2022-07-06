class Solution{
public:
vector<int> euler;
vector<int> level;
    void dfs(int node,int par,int l,vector<int> adj[]){
        //entry
        level[node] = l;
        euler.push_back(node);
        
        for(auto it : adj[node]){
            if(it!=par)
                dfs(it,node,l+1,adj);
        }
        //exit
        euler.push_back(node);
    }
    vector<int> solve(int n, int Q, vector<vector<int> > &Edge, vector<vector<int> > &query) {
       vector<int> adj[n];
       level.resize(n,0);
       for(int i=0;i<Edge.size();i++){
           auto v = Edge[i];
           adj[v[0]].push_back(v[1]);
           adj[v[1]].push_back(v[0]);
       }
       dfs(0,-1,0,adj);
       
       map<int,int>start;
       map<int,int>end;
       for(int i=0;i<euler.size();i++){
          if(start.count(euler[i])==0)
                start[euler[i]] = i;
            end[euler[i]] = i;
       }

       int sz = euler.size();
       int pre_max[sz];  pre_max[0] = level[euler[0]];
       int suff_max[sz]; suff_max[sz-1] = level[euler[sz-1]];
       
       for(int i=1;i<sz;i++){
           pre_max[i] = max(pre_max[i-1], level[euler[i]]);
       }
        for(int i=sz-2;i>=0;i--){
           suff_max[i] = max(suff_max[i+1], level[euler[i]]);
       }
        
        // for(int i=0;i<sz;i++) cout<<pre_max[i]<<" "; cout<<endl;
        // for(int i=0;i<sz;i++) cout<<suff_max[i]<<" "; cout<<endl;
        
        vector<int> v;
        for(auto it:query){
            int a = it[0]; int b = it[1];
            if(level[a] > level[b]) swap(a,b);
            
            int x = start[b];
            int y = end[b];

            int ans = max(pre_max[x-1],suff_max[y+1]);
            v.push_back(ans);
        }
        return v;
    }
    };
    
    
    Input:
N = 5, Q = 2
Edge[][] = {{0, 1},
            {0, 2},
            {1, 3},
            {1, 4}}
query = {{0, 1},
         {1, 4}}
         
    Output:
1 2
Explanation: 
Geekland looks like:
            0
           / \
         1    2
       /   \
     3      4
Query 1: the road connecting (0,1) 
is blocked. Only people living in 
city 0 and 2 can place delivery orders. 
For city 0, distance = 0.
For city 2, distance = 1.
Maximum (city 0, city 1) = 1

Query 2: The road connecting
(1, 4) is blocked. Only people living in
city 0,1,2 and 3 can place delivery orders.
For city 0, distance = 0.
For city 1, distance = 1.
For city 2, distance = 1.
For city 3, distance = 2.
A maximum distance of 2 has to be travelled
for people of city 3. 0 -> 1 -> 3
