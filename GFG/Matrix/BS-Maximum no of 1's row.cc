

class Solution{
public:
        int maxOnes (vector <vector <int>> &mat, int n, int m)
        {
            int maxi=0; int ones=0; int row=0;
            for(int i=0;i<n;i++){
                int l=0;int r=m-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(mat[i][mid]==1)
                        r = mid-1;
                    else
                        l = mid+1;
                }
                ones = m-r-1;
                if(ones>maxi) maxi=ones,row=i;
            }
            return row;
        }
 };

Input:
N = 3, M = 4
Mat[] = {{0 1 1 1},
         {0 0 1 1},
         {0 0 1 1}}
Output: 0
Explanation: Row 0 has 3 ones whereas
rows 1 and 2 have just 2 ones.
