int maxNodeLevel(Node *root)
{
    if(!root) return -1;
    if(!root->left and !root->right) return 0;
    queue<Node*>q;
    q.push(root);
    int level = 0; int ans = 0; int maxi_sz=0;
    while(!q.empty()){
        int sz = q.size();
        if(sz>maxi_sz) maxi_sz = sz , ans = level;
        while(sz--){
            Node* curr = q.front(); q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        level++;
    }
    return ans;
}
