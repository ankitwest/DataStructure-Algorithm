class Solution{
public:
    int pattern(int x,int y,vector<vector<char>>&grid,string word){
        int n =grid.size(); int m = grid[0].size();
        int dx[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
        int dy[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
        auto isValid = [&](int x,int y){
            if(x<0 or y<0 or x>=n or y>=m) return false;
            return true;
        };
        for(int k=0;k<8;k++){
            int new_x = x+dx[k]; int new_y = y+dy[k];
            int i=0;
            for(i=1;i<word.size();i++){
                if(isValid(new_x,new_y) and grid[new_x][new_y]==word[i])
                    new_x = new_x+dx[k],new_y = new_y+dy[k];
                else 
                    break;
            }
            if(i==word.size()) return true;
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> v;
	    int n =grid.size(); int m = grid[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                if(pattern(i,j,grid,word))
	                    v.push_back({i,j});
	            }
	            
	        }
	    }
	    return v;
	}
  };

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.
