

class Solution {
public:
    int solve(vector<int>& A, vector<int>& B,int x){
        int cntA = 0, cntB = 0;  int n = A.size();
        for(int i=0;i<n;i++){
            if(A[i]!=x and B[i]!=x) return -1;
            if(A[i]!=x) cntA++;
            if(B[i]!=x) cntB++;
        }
        return min(cntA,cntB);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans1 = solve(tops,bottoms,tops[0]);
        int ans2 = solve(tops,bottoms,bottoms[0]);
        
        int ans = min(ans1,ans2);
        return ans == -1 ? max(ans1,ans2) : ans;
    }
};
Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
