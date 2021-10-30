
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

    
    
    
    
vector<int> reverseLevelOrder(Node *node)
{
     vector<int> ans;
      if(!node) return ans;
      queue<Node*> q;
      q.push(node);
      
      while(!q.empty()){
          vector<int> v;
          int n = q.size();
          for(int i=0;i<n;i++){
              Node* curr = q.front(); q.pop();
              
              v.push_back(curr->data);
              if(curr->left)
                q.push(curr->left);
             if(curr->right)
                q.push(curr->right);
          }
          reverse(v.begin(),v.end());
          for(auto x:v) ans.push_back(x);
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
