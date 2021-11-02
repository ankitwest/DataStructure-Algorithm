
// Root to Leaf Path (everyone)

class Solution{
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


  

// Root to Leaf Path with Target Path Sum
  
class Solution
{
    public:
    void helper(Node* root,bool &found,int &curr_sum,int target){
        if(!root) return ;
        curr_sum = curr_sum + root->data;
        helper(root->left,found,curr_sum,target);
        helper(root->right,found,curr_sum,target);
        if(!root->left and !root->right and curr_sum==target)
            found = true;
        curr_sum -= root->data;
    }
  
    bool hasPathSum(Node *root, int target) 
    {
    bool found = false;
    int curr_sum = 0;
    helper(root,found,curr_sum,target);
    return found;
   }
};
Expected Time Complexity: O(N)

  
  
  
// Root to Leaf Path with Maximum Path Sum
  
class Solution{
    public:
    void helper(Node* root,int &curr_sum,int &max_sum){
        if(!root) return ;
        curr_sum = curr_sum + root->data;
        helper(root->left,curr_sum,max_sum);
        helper(root->right,curr_sum,max_sum);
        if(!root->left and !root->right)
            max_sum = max(max_sum,curr_sum);
        curr_sum -= root->data;
        
    }
    int maxPathSum(Node* root)
    {
       int max_sum = -1;
       int curr_sum = 0;
       helper(root,curr_sum,max_sum);
       return max_sum;
       
    }
};
Expected Time Complexity: O(n) , where n = number of nodes
