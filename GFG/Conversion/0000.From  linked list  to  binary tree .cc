void convert(Node *head, TreeNode *&root) {
     queue<TreeNode*>q;
    root = new TreeNode(head->data);
    q.push(root);
    
    while(!q.empty()){
        TreeNode* curr = q.front();q.pop();
        if(head->next){
            curr->left = new TreeNode(head->next->data);
            q.push(curr->left);
            head = head->next;
        }else if(head->next){
            curr->right = new TreeNode(head->next->data);
            q.push(curr->right);
            head = head->next;
        }
    }
}
