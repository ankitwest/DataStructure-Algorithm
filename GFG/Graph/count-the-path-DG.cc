class Solution{
  public:
    void dfs(int s,int d,vector<vector<int>>edges,int &ctr){
        if(s==d){
            ctr++; return;
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==s)
                dfs(edges[i][1],d,edges,ctr);
        }
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    int ctr=0;
	    dfs(s,d,edges,ctr);
	    return ctr;
	}
};
