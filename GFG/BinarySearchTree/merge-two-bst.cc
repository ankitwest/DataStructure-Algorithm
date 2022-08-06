class Solution{
    public:
    void inorder(Node* root, vector<int> &v){
        if(!root) return ;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(vector<int> &a, vector<int> &b){
        int i=0; int j=0; int n = a.size(); int m = b.size();
        vector<int> ans(n+m,0); int k = 0;
        
        while(i<n and j<m){
            if(a[i]<=b[j]) 
                ans[k++] = a[i++];
            else 
                ans[k++] = b[j++];
        }
        while(i<n) ans[k++] = a[i++];
        while(j<m) ans[k++] = b[j++];
        return ans;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> v1,v2;
       inorder(root1,v1);
       inorder(root2,v2);
       
       return merge(v1,v2);
    }
   
   
   
   
   public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root,vector<int> &v){
        if(!root) return ;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(vector<int> &a,vector<int> &b){
        int i=0; int j=0; int n = a.size(); int m = b.size();
        vector<int> ans;
        while(i<n and j<m){
            if(a[i]<=b[j]) ans.push_back(a[i]),i++;
            else if(b[j]<a[i]) ans.push_back(b[j]),j++;
        }
        if(i==n){
            while(j<m) ans.push_back(b[j++]);
        }
        if(j==m){
            while(i<n) ans.push_back(a[i++]);
        }
        return ans;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> v1,v2;
       inorder(root1,v1);
       inorder(root2,v2);
       
       return merge(v1,v2);
    }
};
Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
