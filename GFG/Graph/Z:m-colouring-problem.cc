class Solution{
vector<int> color; 
int V; int M;

    bool safeColor(int curr,int c,bool graph[101][101]){
        for(int it=0;it<V;it++){
            if(it==curr) continue;
            if(graph[it][curr]==1 and color[it]==c) return false;
        }
        return true;
    }
    bool coloring(int node,bool graph[101][101]){
        if(node==V) //[0,V-1]
        return true; 
        
        for(int c=0;c<M;c++) //color loop
        {  
            if(safeColor(node,c,graph))
            {
                color[node] = c;
                if(coloring(node+1,graph)) return true;
                color[node] = -1;
            }
        }
        return false;
    }
public:    
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        V = n; M = m;
        color.resize(V,-1);
        return coloring(0,graph);
    }
};
