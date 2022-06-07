// Flatten binary tree to linked list
class Solution
{
    public:
    void flatten(Node *root)
    {
        if(!root or !root->left and !root->right)
            return ;
        if(root->left){
            flatten(root->left);
            Node* tempRight = root->right;
            root->right = root->left;
            root->left = NULL;
            
            Node* t = root->right;
            while(t->right){
                t = t->right;
            }
            t->right = tempRight;
        }
        flatten(root->right);
    }
};

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        Node* prev = NULL;
        while(curr){
            if(curr->left){
                prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6

Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.





  
  
 
  //Ffrom  linked list  to  binary tree 
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
  
  N = 5
K = 5->4->3->2->1
Output: 5 4 3 2 1
  
     5
   /  \
  4    3
 / \
2    1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
