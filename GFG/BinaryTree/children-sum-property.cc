class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    bool childSum(Node* root){
        if(!root) return true;
        if(!root->left and !root->right) return true;
        
        int sum = 0;
        if(root->left)
            sum += root->left->data;
        if(root->right)
            sum += root->right->data;
        
        return root->data==sum and childSum(root->left) and childSum(root->right);
    }
    int isSumProperty(Node *root)
    {
     return childSum(root);
    }
};




// BFS approach
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root) return true;
        if(!root->left and !root->right) return true;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            int sum = 0;
            if(curr->left){
                sum += curr->left->data;
                q.push(curr->left);
            }
            if(curr->right){
                sum += curr->right->data;
                q.push(curr->right);
            }
            if(sum>0 and sum!=curr->data){
                return false;
            }
        }
        return true;
    }
};
