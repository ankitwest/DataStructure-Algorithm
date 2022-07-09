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

class Solution {
    Node* lca(Node* root,int a,int b){
        if(!root) return NULL;
        
        if(root->data == a or root->data==b) return root;
        
        Node* l = lca(root->left,a,b);
        Node* r = lca(root->right,a,b);
        
        if(l and r) return root;
        if(l) return l;
        return r;
    }
  public:
    int lca3Nodes(Node* root, int p, int q, int r) {
        
        Node* l1 = lca(root,p,q);
        Node* l2 = lca(root,l1->data,r);
        
        return l2->data;
    }
};
