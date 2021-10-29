class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
    vector<int> v;
      
    if (root == NULL) return v;
        
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
    int n=q.size();
      for(int i=0;i<n;i++){     
          Node* fr = q.front();   q.pop();

          if(i == n-1) v.push_back(fr->data);
          if(fr->left)  q.push(fr->left);
          if(fr->right)  q.push(fr->right);
           
        }
      }
    }
};


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
