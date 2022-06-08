

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(); int m = B.size(); 
        vector<vector<int>> ans;
        int i=0,j=0;   
        while(i<n and j<m){
            int start = max(A[i][0],B[j][0]);
            int end   = min(A[i][1],B[j][1]);
            if(start <= end)    // if their is locking 
                ans.push_back({start,end});
            if(A[i][1] < B[j][1])    //  comparing exhausted end
                i++;
            else 
                j++;
        }
        return ans;
    }
};
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
