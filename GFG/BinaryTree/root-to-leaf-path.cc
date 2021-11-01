
Class Solution{
public:
void leafPath(Node* root,vector<int> &v,vector<vector<int>> &ans){
     if(!root) return ;
     v.push_back(root->data);
     leafPath(root->left,v,ans);
     leafPath(root->right,v,ans);
  
     if(!root->left and !root->right) 
        ans.push_back(v);
    v.pop_back();
 }
vector<vector<int>> Paths(Node* root)
  {
    vector<vector<int>> ans;
    vector<int> v;
    if(!root) return ans;
    
    leafPath(root,v,ans);
    return ans;
  }
};

Expected Time Complexity: O(N).
