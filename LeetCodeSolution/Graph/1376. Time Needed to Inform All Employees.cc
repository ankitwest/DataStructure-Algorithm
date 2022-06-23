class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(i!=headID)
                graph[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans = 0;
        while(!q.empty()){
            auto [id, timeTaken] = q.front();q.pop();
            int dur = informTime[id] + timeTaken;
            ans = max(ans, dur);
            
            for(auto node : graph[id]){
                q.push({node,dur});
            }
        }
        return ans;
    }
};

Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
