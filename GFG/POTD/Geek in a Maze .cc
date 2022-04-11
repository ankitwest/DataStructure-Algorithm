


class Solution{
public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		queue<array<int,4>> q;
		if(mat[r][c]=='#') return 0;
		q.push({r,c,0,0});
		mat[r][c] = '1';
	
    	int count = 1;
		while(!q.empty()){
		    auto curr = q.front(); q.pop();
		    int x = curr[0];int y = curr[1];
		    int up = curr[2];int down = curr[3];
		    
		    if(y-1>=0 and mat[x][y-1]=='.'){
		        q.push({x,y-1,up,down});
		        mat[x][y-1] = '1';
		        count++;
		    }
		     if(y+1<m and mat[x][y+1]=='.'){
		        q.push({x,y+1,up,down});
		        mat[x][y+1] = '1';
		        count++;
		    }
		     if(x-1>=0 and up!=u and mat[x-1][y]=='.'){
		        q.push({x-1,y,up+1,down});
		        mat[x-1][y] = '1';
		        count++;
		    }
		    if(x+1<n and down!=d and mat[x+1][y]=='.'){
		        q.push({x+1,y,up,down+1});
		        mat[x+1][y] = '1';
		        count++;
		    }
        }
		return count;
	}
  };
