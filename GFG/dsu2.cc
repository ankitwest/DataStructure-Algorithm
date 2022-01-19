
GFG Q
Disjoint set (Union-Find)


int find(int parent[],int node)
{
      if(node==parent[node])
        return node;
        return parent[node] = find(parent,parent[node]);
}
void unionSet(int parent[],int u,int v)
{
	u = find(parent,u);
	v = find(parent,v);
	
	if(u==v) return;
	parent[u] = v;
}





Number of connected components 


class Solution
{
  public:
    int findPar(int node,int parent[]){
        if(node==parent[node])
            return node;
        return parent[node] = findPar(parent[node],parent);
    }
    void unionNodes( int a, int b, int parent[], int rank[], int n) 
    {
        a = findPar(a,parent);
        b = findPar(b,parent);
        
        if(rank[a]>rank[b]) parent[b] = a;
        else if(rank[b]>rank[a]) parent[a] = b;
        else{
            parent[b] = a;  rank[a]++;
        }
    }
    
    //Function to determine number of connected components.
    int findNumberOfConnectedComponents( int n, int parent[], int rank[]) 
    {
        set<int> s;
        for(int i=1;i<=n;i++){
            s.insert(findPar(i,parent));
        }
        return s.size();
    }
  };






3. Detect Cycle using DSU 


class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int findPar(int x,int par[]){
        if(x == par[x])
            return x;
        return par[x] = findPar(par[x],par);
    }
    bool unionCycle(int a,int b,int par[],int rank[]){
        int ax = findPar(a,par);
        int bx = findPar(b,par);
        
        if(ax==bx and a!=b) return true;
        
        if(rank[ax]>rank[bx]) par[bx] = ax;
        if(rank[bx]>rank[ax]) par[ax] = bx;
        else{
            par[bx] = ax;  rank[ax]++;
        }
        return false;
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    int rank[V];
	    int par[V];
	    
	    for(int i=0;i<V;i++){
	        par[i] = i; rank[i] = 0;
	    }
	    
	    for(int node=0;node<V;node++){
	        for(auto child : adj[node]){
	            if(child>node and unionCycle(child,node,par,rank)==true)
	                return 1;
	        }
	    }
	    return 0;
	}
};
