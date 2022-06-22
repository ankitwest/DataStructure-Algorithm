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
                if(i==sz-1)  curr->next = NULL;
                else curr->next = q.front();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each 
