


// bfs

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front(); q.pop();
                if(i==sz-1) curr->next =  NULL;
                else curr->next = q.front();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};
