class Solution{
  public:
        void dfs(int sr, int sc,vector<vector<int>>& image,int newColor,int oldColor,vector<vector<int>>& vis){
        if(sr<0 or sc<0 or sr>=image.size() or sc>=image[0].size() or image[sr][sc]!=oldColor) return;
        if(vis[sr][sc]) return ;

        image[sr][sc]=newColor;
        vis[sr][sc]=1;
       
        dfs(sr+1,sc,image,newColor,oldColor,vis);
        dfs(sr-1,sc,image,newColor,oldColor,vis);
        dfs(sr,sc+1,image,newColor,oldColor,vis);
        dfs(sr,sc-1,image,newColor,oldColor,vis);
    }
  
  
  
      void bfs(int sr,int sc,vector<vector<int>>& image,int newColor,int oldColor){
        if(oldColor==newColor) return;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
            
        queue<pair<int,int>> q;
        image[sr][sc]=newColor;
        q.push({sr,sc});
        while(!q.empty()){
            auto p = q.front();q.pop();
        for(int k=0;k<4;k++){
            int new_x = p.first + dx[k];
            int new_y = p.second + dy[k];
            if(new_x<0 or new_y<0 or new_x>=image.size() or new_y>=image[0].size() or image[new_x][new_y]!=oldColor)  continue;
            image[new_x][new_y]=newColor; 
            q.push({new_x,new_y});    
          }
        }
      
    }
  
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        int oldColor = image[sr][sc];
        dfs(sr,sc,image,newColor,oldColor);
        return image;
    }
};

