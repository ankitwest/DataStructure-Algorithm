/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> m;
        map<int,int> parent,child;
        
        for(auto v : descriptions){
            if(m.find(v[0])==m.end()){
                TreeNode* pr = new TreeNode(v[0]);
                m[v[0]] = pr;
            }
            if(m.find(v[1])==m.end()){
                TreeNode* ch = new TreeNode(v[1]);
                m[v[1]] = ch;
            }
            
            if(v[2]==1) m[v[0]]->left = m[v[1]];
            else m[v[0]]->right = m[v[1]];
            
            parent[v[0]]++;
            child[v[1]]++;
        }
        
        TreeNode* ans = NULL;
        for(auto [x,y]:m){
            if(parent.find(x)!=parent.end() and child.find(x)==child.end()){
                ans = m[x]; break;
            }
        }
        return ans;
    }
};

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
