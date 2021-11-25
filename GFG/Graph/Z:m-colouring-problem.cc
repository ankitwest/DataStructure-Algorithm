class Solution{
  public:
  bool safeColor(bool graph[101][101],int node,int c,vector<int> &color,int V){
    for(int i=0;i<V;i++){
        if(i==node) continue;
        if(graph[i][node]==1 and color[i]==c) return false;
    }
    return true;
}
bool coloring(bool graph[101][101],int node,vector<int> &color,int V,int m){
    if(node==V) return true;
    
    for(int k=0;k<m;k++){
        if(safeColor(graph,node,k,color,V)){
            color[node]=k;
            if(coloring(graph,node+1,color,V,m)) return true;
            color[node]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V,-1);
    return coloring(graph,0,color,V,m);
}
};
