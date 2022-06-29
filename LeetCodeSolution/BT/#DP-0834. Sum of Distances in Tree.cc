class Solution {
    const static int maxN = 3e4+5;
    vector<int> adj[maxN];
    vector<int> count;
    vector<int> res;
    void dfs(int node, int par){
        for(auto i : adj[node]){
            if(i==par) continue;
            dfs(i, node);
            count[node] += count[i];
            res[node] += res[i] + count[i];
        }
    }
    void dfs2(int node, int par){
        for(auto i : adj[node]){
            if(i==par) continue;
            res[i] = res[node] - count[i] + count.size() - count[i];
            dfs2(i, node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n,0);
        count.resize(n,1);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1);
        dfs2(0,-1);
        
        return res;
    }
};

/*
 dfs2 which is the actual dp part. 
The Original problem
We can run the dfs function above for every node and get the solution. This will result in O(N * N) time complexity. But we can do this in O(N) time using a technique popularly known as re-rooting techinque.

So,
res[1] = res[0] - count[1] + n - count[1]
i.e
res[new_root] = res[root] - count[new_root] + n - count[new_root]


 https://leetcode.com/problems/sum-of-distances-in-tree/discuss/1308366/C%2B%2B-solution-using-dfs-with-explanation-O(N)-time-complexity
 
 */
