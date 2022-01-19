
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
