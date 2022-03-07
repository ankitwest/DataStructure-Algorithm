class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int n, int m, vector<vector<int>> after){
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int z=0,x=0,y=0;
                if(i>=1 and j>=1) z = after[i-1][j-1];
                if(i>=1) x = after[i-1][j];
                if(j>=1) y = after[i][j-1];
                
                after[i][j] -= x + y - z;
            }
        }
        return after;
    }
};

// Question

// res = 0;
// for(i = 0; i <= x; i++){
//     for( j = 0; j <= y; j++){              
//         res += before(i,j);
//     }
// }
// after(x,y) = res;
