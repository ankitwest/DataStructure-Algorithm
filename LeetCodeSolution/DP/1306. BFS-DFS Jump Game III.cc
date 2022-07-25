class Solution {
    bool dfs(int i,vector<int> &arr, vector<int> &vis){
        if(i<0 or i>=arr.size() or vis[i]) return false;
        if(arr[i]==0) return true;
        
        vis[i] = 1;
        return dfs(i+arr[i],arr,vis) or dfs(i-arr[i],arr,vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        return dfs(start,arr,vis);
    }
};




//bfs
class Solution2 {
public:
    bool canReach(vector<int>& A, int start) {
        queue<int> q;  int n = A.size();
        q.push(start);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(A[cur] == 0) return true;                        // target reached
            if(A[cur] < 0)  continue;                           // already visited - stop further exploration of this path
            if(cur + A[cur] < n)       
                    q.push(cur + A[cur]);                       // try forward jump
            if(cur - A[cur] >= 0)      
                    q.push(cur - A[cur]);                       // try backward jump
            A[cur] *= -1;                                       // mark current index as visited by negating
        }
        return false;             // explored all array without reaching target
    }
};
