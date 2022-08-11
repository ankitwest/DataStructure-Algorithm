
// Given 2 Arrays of Inorder and preorder traversal. Construct a tree 
    https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution{
unordered_map<int,int>m;
    Node* build(int in[],int pre[],int &start,int inS,int inE){
        if(inS>inE) return NULL;
        Node* root = new Node(pre[start++]);
        if (inS==inE)  return root;
           
        int mid = m[root->data];
        
        root->left = build(in,pre,start,inS,mid-1);
        root->right = build(in,pre,start,mid+1,inE);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        m.clear();
        for(int i=0;i<n;i++) m[in[i]]=i;
        int start=0; 
        return build(in,pre,start,0,n-1);
    }
};
Expected Time Complexity: O(N).

   N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0   (driver)
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5










Given 2 Arrays of Inorder and postorder traversal. Construct a tree 
    
    class Solution{
        public:
        unordered_map<int,int>m;
        Node* build(int in[],int post[],int &end,int inLB,int inUB){
            if(inLB>inUB) return NULL;
            Node* root = new Node(post[end--]);
            if(inLB==inUB) return root;

            int mid = m[root->data];
            root->right = build(in,post,end,mid+1,inUB);
            root->left = build(in,post,end,inLB,mid-1);

            return root;
        }
        Node *buildTree(int in[], int post[], int n) {
            m.clear();
            for(int i=0;i<n;i++) m[in[i]]=i;
            int end=n-1;
            return build(in,post,end,0,n-1);
        }
    };
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
    
