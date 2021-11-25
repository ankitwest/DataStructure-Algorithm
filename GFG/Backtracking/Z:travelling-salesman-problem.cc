// min cost to travel from city 0 to all round and come to back to city 0
class Solution{
  public:
void backtracking(int i,vector<vector<int>> &matrix,int city,vector<int> &vis,int cost,int &ans){
    if(city==0){
        ans = min(ans,cost+matrix[i][0]);
        return ;
    }
    for(int j=0;j<matrix.size();j++){
        if(!vis[j]){
            vis[j]=1;
            backtracking(j,matrix,city-1,vis,cost+matrix[i][j],ans);
            vis[j]=0;
        }
    }
    return ;
}
int total_cost(vector<vector<int>>matrix){
    int n=matrix.size(); int N=n;
    int ans = INT_MAX;
    vector<int> vis(N,0);
    vis[0]=1;
    backtracking(0,matrix,N-1,vis,0,ans);
    return ans;
    }
};
