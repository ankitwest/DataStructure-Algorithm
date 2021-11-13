class Solution{
  public:
    void inorder(Node* root,int K,int &ans,int &idx){
        if(!root) return ;
        
        inorder(root->left,K,ans,idx);
        idx++;
        if(K==idx){
            ans = root->data;
            return;
        }
        inorder(root->right,K,ans,idx);
    }
    int KthSmallestElement(Node *root, int K) {
        int idx=0; int ans=-1;
        inorder(root,K,ans,idx);
        return ans;
    }
};
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).



class Solution{
   public:
    void inorder(Node* root,int K,int &ans,int &idx){
        if(!root) return ;
        
        inorder(root->right,K,ans,idx);
        idx++;
        if(K==idx){
            ans = root->data;
            return;
        }
        inorder(root->left,K,ans,idx);
    }
    int kthLargestElement(Node *root, int K){
        int idx=0; int ans=-1;
        inorder(root,K,ans,idx);
        return ans;
    }
};
