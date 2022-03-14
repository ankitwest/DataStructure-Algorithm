class Solution{
public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
       int n = matrix.size(); pair<int,int> ans;
        int m = matrix[0].size();
        
        queue<pair<int,int>> q;
        q.push({0,0});
        string dir = "right";
        int new_x=-1;int new_y = -1;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first;int y = curr.second;
             
            if(matrix[x][y]==0){
                if(dir=="right") new_x=x+0, new_y=y+1;
                else if(dir=="down") new_x=x+1, new_y=y+0;
                else if(dir=="left") new_x=x+0, new_y=y-1;
                else if(dir=="up") new_x=x-1, new_y=y+0;
                if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) {return {x,y};}
            }else{
                matrix[x][y]=0;
                if(dir=="right") new_x=x+1, new_y=y+0,dir="down";
                else if(dir=="down") new_x=x+0, new_y=y-1,dir="left";
                else if(dir=="left") new_x=x-1, new_y=y+0,dir="up";
                else if(dir=="up") new_x=x+0, new_y=y+1,dir="right";
                if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) {return {x,y};}
            }
            q.push({new_x,new_y});
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return ans;
        return {};
    }
};
