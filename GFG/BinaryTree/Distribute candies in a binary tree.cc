class Solution
{
    int moves = 0;
    int solve(Node* root){
        if(!root) return 0;
        
        if(root and !root->left and !root->right){
            return root->key - 1;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        moves += abs(l) + abs(r);
        
        return abs(l) + abs(r) + root->key - 1;
    }
public:
    int distributeCandy(Node* root)
    {
        if(!root) return 0;
       
       solve(root);
       return moves;
    }
};
