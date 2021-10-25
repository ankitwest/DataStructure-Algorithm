class Solution{
public:
    bool isHeap(struct Node* tree) {
        if(tree==NULL) return true;
        queue<Node*>q;
        q.push(tree);
        bool flag=false;
        while(!q.empty()){
            Node* curr = q.front();q.pop();
            if(curr->left){
                if(flag or curr->left->data > curr->data)  
                    return false;
                q.push(curr->left);
            }else
                flag = 1;
            if(curr->right){
                if(flag or curr->right->data > curr->data)
                    return false;
                q.push(curr->right);
            }else
                flag=1;
        }
        
        return true;
    }
};
