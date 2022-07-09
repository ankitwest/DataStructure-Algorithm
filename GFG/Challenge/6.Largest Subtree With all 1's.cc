Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Valid{
public:
    bool crt;
    int cnt;
    Valid(bool ct,int c){
        crt = ct;
        cnt = c;
    }
};

class Solution {
    int ans = 0;
    Valid solve(Node* root){
        if(!root) 
            return Valid(true,0);
        
        Valid l = solve(root->left);
        Valid r = solve(root->right);
        
        if(root->data==1){
            ans = max(ans,l.cnt + r.cnt + 1);
            return Valid(true,l.cnt + r.cnt + 1);
        }
        return Valid(false,0);
    }
  public:
    int maxSubtreeAll1s(Node* root) {
        solve(root);
        return ans;
    }
};
