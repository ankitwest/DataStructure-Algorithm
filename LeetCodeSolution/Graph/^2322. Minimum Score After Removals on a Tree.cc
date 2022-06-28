const int N = 1e3+1;
vector<int> adj[N];
vector<int> val(N);
vector<int> subtree_xor(N);
vector<vector<bool>> is_ancestor(N, vector<bool>(N, false)); 

class Solution {
    void MarkAncestor (const int root,int src, int par) {
        is_ancestor [root][src] = true;  //  root is anc of src
        
        for (auto i : adj[src]) {
            if (i == par) continue;
            MarkAncestor (root, i, src);
        }
    }

    void dfs (int src, int par) {    
        subtree_xor[src] = val[src];  
        MarkAncestor (src, src, par);
        
        for (auto i : adj[src]) {
            if (i == par) continue;
            
            dfs (i, src);
            subtree_xor[src] ^= subtree_xor[i];
        }
    }
    
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            adj[j].clear();
            for (int i = 0; i < n; i++) is_ancestor[j][i] = false;
        }
        
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) val[i] = nums[i];
        
        dfs(0, -1);
        
        int ans = INT_MAX;
        for (int c1 = 1; c1 < n; c1++) {
            for (int c2 = c1+1; c2 < n; c2++) {
                if (c1 == c2) continue;
                                
                if (is_ancestor[c1][c2]) { //  c1 is anc of c2
                    int comp1 = subtree_xor[c2];
                    int comp2 = subtree_xor[c1] ^ subtree_xor[c2];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    int maxi = max({comp1,comp2,comp3}); int mini = min({comp1,comp2,comp3});
                    ans = min (ans, maxi-mini);
                }
                else if (is_ancestor[c2][c1]) {
                    int comp1 = subtree_xor[c1];
                    int comp2 = subtree_xor[c2] ^ subtree_xor[c1];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    int maxi = max({comp1,comp2,comp3}); int mini = min({comp1,comp2,comp3});
                    ans = min (ans, maxi-mini);
                }
                else {
                    int comp1 = subtree_xor[c1];
                    int comp2 = subtree_xor[c2];
                    int comp3 = subtree_xor[0] ^ comp1 ^ comp2;
                    
                    int maxi = max({comp1,comp2,comp3}); int mini = min({comp1,comp2,comp3});
                    ans = min (ans, maxi-mini);
                }
            }
        }
        return ans;
    }
};


Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
Output: 9
Explanation: The diagram above shows a way to make a pair of removals.
- The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
- The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
- The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
It can be shown that no other pair of removals will obtain a smaller score than 9.
