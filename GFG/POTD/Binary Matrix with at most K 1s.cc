class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        int countDP[R][C];
        memset(countDP, 0, sizeof(countDP));

        countDP[0][0] = M[0][0];
        for (int i = 1; i < R; i++)
            countDP[i][0] = countDP[i-1][0] + M[i][0];
        for (int j = 1; j < C; j++)
            countDP[0][j] = countDP[0][j-1] + M[0][j];
        for (int i = 1; i < R; i++)
            for (int j = 1; j < C; j++)
                countDP[i][j] = M[i][j] + countDP[i-1][j] + countDP[i][j-1] - countDP[i-1][j-1];
          
        // Loop to solve Queries
        vector<int> res(Q);
        for (int q = 0; q < Q; q++) {
            int i = q_i[q];
            int j = q_j[q];
           
            int min_dist = min(min(i, j), min(R - i - 1, C - j - 1));
            int ans = -1;
            for (int k = 0; k <= min_dist;k++) {
                int x1 = i - k, x2 = i + k;
                int y1 = j - k, y2 = j + k;
                  
                int count = countDP[x2][y2];
                if (x1 > 0)
                    count -= countDP[x1 - 1][y2];
                if (y1 > 0)
                    count -= countDP[x2][y1 - 1];
                if (x1 > 0 && y1 > 0)
                    count += countDP[x1 - 1][y1 - 1];
      
                if (count > K)
                    break;
                ans = 2 * k + 1;
            }
            res[i] = ans;
        }
        return res;
    }
};


//submitted
class Solution {
  public:
    bool isPossible(int x, int y, int mid, int R, int C, vector<vector<int>>& sum, int k){
        int x1 = x + mid, y1 = y + mid, x2 = x - mid, y2 = y - mid;
        int ones = sum[x1][y1];
        ones -= x2 - 1 >= 0 ? sum[x2 - 1][y1] : 0;
        ones -= y2 - 1 >= 0 ? sum[x1][y2 - 1] : 0;
        ones += (y2 - 1 >= 0 && x2 - 1 >= 0 )? sum[x2 - 1][y2 - 1] : 0;
        return ones <= k;
    }
  
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        vector<vector<int>> sum(R, vector<int>(C, 0));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                sum[i][j] = M[i][j];
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 1; j < C; j++){
                sum[i][j] += sum[i][j - 1];
            }
        }
        for(int j = 0; j < C; j++){
            for(int i = 1; i < R; i++){
                sum[i][j] += sum[i - 1][j];
            }
        }
        vector<int> ans(Q,0);
        for(int i = 0; i < Q; i++){
            int x = q_i[i], y = q_j[i];
            int down = min(R - 1 - x, C - 1 - y), up = min(x, y);
            int low = 0, high = min(up, down);
            while(low <= high){
                int mid = low + (high - low)/2;
                if(isPossible(x, y, mid, R, C, sum, K)){
                    low = mid + 1;
                    ans[i] = 1 + 2*mid;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};

/*


//----O(R*C + Q*MIN_DIST) Approach -----------
vector<int> largestSquare(vector<vector<int>> m, int r, int c, int k, int q, int q_i[], int q_j[]) {
    vector< vector<int> > no(r, vector<int>(c)) ;
    no[0][0] = m[0][0] ;
    for(int i=1 ; i<r ; i++)
        no[i][0] = no[i-1][0] + m[i][0] ;
    for(int j=1 ; j<c ; j++)
        no[0][j] = no[0][j-1] + m[0][j] ;
    
    for(int i=1 ; i<r ; i++)
        for(int j=1 ; j<c ; j++)
            no[i][j] = m[i][j] + no[i-1][j] + no[i][j-1] - no[i-1][j-1] ;
    vector<int> ans(q) ;
    for(int i=0 ; i<q ; i++){
        int sr = q_i[i], sc = q_j[i] ;
        for(int t = 0 ; sr+t < r && sr-t >= 0 && sc+t < c && sc-t >= 0 ; t++){
            int total = no[sr+t][sc+t] ;
            total -= (sc-t-1>=0 ? no[sr+t][sc-t-1] : 0) ;
            total -= (sr-t-1>=0 ? no[sr-t-1][sc+t] : 0) ;
            total += (sc-t-1>=0 && sr-t-1>=0 ? no[sr-t-1][sc-t-1] : 0) ;
            if(total <= k )
                ans[i] = 2*t+1 ;
            else
                break ;
        }
    }
    return ans ;
}
 
 */
 
 /*

-------------Optimized-----------

// ----- O(R*C + Q*log(MinDist) Approach------
vector<int> largestSquare(vector<vector<int>> m, int r, int c, int k, int q, int q_i[], int q_j[]) {
    vector< vector<int> > no(r, vector<int>(c)) ;
    no[0][0] = m[0][0] ;
    for(int i=1 ; i<r ; i++)
        no[i][0] = no[i-1][0] + m[i][0] ;
    for(int j=1 ; j<c ; j++)
        no[0][j] = no[0][j-1] + m[0][j] ;
    
    for(int i=1 ; i<r ; i++)
        for(int j=1 ; j<c ; j++)
            no[i][j] = m[i][j] + no[i-1][j] + no[i][j-1] - no[i-1][j-1] ;
    vector<int> ans(q,0) ;
    for(int i=0 ; i<q ; i++){
        int sr = q_i[i], sc = q_j[i] ;
        int left = 0, right = min(r-sr-1, min(sr, min(c-sc-1,sc))) , m  ;
        while(left<=right){
            m = (left+right)/2 ;
            int total = no[sr+m][sc+m] ;
            total -= (sc-m-1>=0 ? no[sr+m][sc-m-1] : 0) ;
            total -= (sr-m-1>=0 ? no[sr-m-1][sc+m] : 0) ;
            total += (sc-m-1>=0 && sr-m-1>=0 ? no[sr-m-1][sc-m-1] : 0) ;
            if(total <= k )
                left = m+1 , ans[i] = 2*m+1 ;
            else
                right = m-1 ;
        }
    }
    return ans ;
}

*/
