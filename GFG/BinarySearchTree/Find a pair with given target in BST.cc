public:
    // root : the root Node of the given BST
    // target : the target sum
    // bool ans = false;
    int solve(Node* root,set<int>& s,int tar){
        if(!root) return false;
        
        if(solve(root->left,s,tar)) return true;
        
        if(s.count(tar - root->data)){
             return true;
        }else
            s.insert(root->data);
            
        return solve(root->right,s,tar);
    }
    int isPairPresent(struct Node *root, int target)
    {
        set<int> s;
        return solve(root,s,target);
        // return ans;
    }
