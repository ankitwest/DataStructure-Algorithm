
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int> v;
      if(!node) return v;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          int n = q.size();
          for(int i=0;i<n;i++){
              Node* curr = q.front(); q.pop();
              
              v.push_back(curr->data);
              if(curr->left)
                q.push(curr->left);
             if(curr->right)
                q.push(curr->right);
          }
      }
      return v;
    }
};


Expected Time Complexity: O(N)
