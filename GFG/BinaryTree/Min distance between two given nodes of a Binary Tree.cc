class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dist(Node* root,int a){
        if(!root) return 0;
        if(root->data==a) return 1;
        
        int x = dist(root->left,a);
        int y = dist(root->right,a);
        
        if(!x and !y) return 0;
        return x+y+1;
    }
    Node* lca(Node* root,int a,int b){
        if(!root) return NULL;
        if(root->data==a or root->data==b) return root;
        
        Node* l = lca(root->left,a,b);
        Node* r = lca(root->right,a,b);
        
        if(l and r) return root;
        if(l) return l;
        if(r) return r;
        
        return NULL;
    }
    int findDist(Node* root, int a, int b) {
        Node* lca_ = lca(root,a,b);
        
        int d = dist(lca_,a) + dist(lca_,b);
        return d-2;
    }
};
