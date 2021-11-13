class Solution{
  public:
  Node* inpre(Node* root){
      root=root->left;
      while(root->right){
          root=root->right;
      }
      return root;
  }
  Node* insuc(Node* root){
      root=root->right;
      while(root->left){
          root=root->left;
      }
      return root;
  }
  void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
  {
      if(!root) return ;
      if(root->key==key){
          if(root->left) pre = inpre(root);
          if(root->right) suc = insuc(root);
          return;
      }else if(key<root->key){
          suc=root;
          findPreSuc(root->left,pre,suc,key);
      }
      else if(key>root->key){
          pre=root;
          findPreSuc(root->right,pre,suc,key);
      }
  }
};




// Inorder Successor

// class Solution{
//   public:
//     // returns the inorder successor of the Node x in BST (rooted at 'root')
//     Node* insuc(Node* root){
//         root=root->right;
//         while(root->left){
//             root=root->left;
//         }
//         return root;
//     }
//     Node* suc=NULL;
//     Node * inOrderSuccessor(Node *root, Node *x)
//     {
//         if(!root) return NULL;
//         if(root->data==x->data){
//             if(root->right) suc = insuc(root);
//             return suc;
//         }else if(x->data>root->data){
//             inOrderSuccessor(root->right,x);
//         }else if(x->data<root->data){
//             suc = root;
//             inOrderSuccessor(root->left,x);
//         }
//         return suc;
//     }
// };
