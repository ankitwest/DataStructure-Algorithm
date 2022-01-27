class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(start);
        vector<bool> seen(n);
        seen[start] = true;
        
        while (!q.empty()) {
            // Get the current node.
            int node = q.front();
            q.pop();
            
            // Check if we have reached the target node.
            if (node == end) {
                return true;
            }
            
            // Add all neighbors to the stack.
            for (int neighbor : adjacency_list[node]) {
                // Check if neighbor has been added to the queue before.
                if (!seen[neighbor]) {
                    seen[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};
