class Solution{
public:    
    bool isCompleteBT(Node* root){
        if(!root) return true;
        
        queue<Node*> q;
        q.push(root);
        bool flag = false;
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr->left){
                if(flag) return false;
                q.push(curr->left);
            }else
                flag = true;
                
                
            if(curr->right){
                if(flag) return false;
                q.push(curr->right);
            }else
                flag = true;
        }
        
        return true;
    }
};
