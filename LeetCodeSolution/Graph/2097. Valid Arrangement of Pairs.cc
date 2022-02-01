class Solution {
public:
    unordered_map<int,stack<int>> graph;
    vector<vector<int>> path;
    
    void euler(int start){
        auto& st = graph[start];
        while(!st.empty()){
            int n = st.top(); st.pop();
            euler(n);
            //postorder
            path.push_back({start,n});
        }
    }
    int findStart(unordered_map<int,int> &degree){
        int start = -1;
        for(auto& [i,cnt]:degree){
            if(cnt == 1) start = i;
        }
        
        if(start==-1) start = graph.begin()->first;
        
        return start;
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> degree;
        for(auto &pair:pairs){
            int u = pair[0],v = pair[1];
            graph[u].push(v);
            degree[u]++;
            degree[v]--;
        }
        
        int start = findStart(degree);
        
        euler(start);
        reverse(path.begin(),path.end());
        return path;
    }
};


Example 1:

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
Example 2:

Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
Example 3:

Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
 
