
//Level order traversal
class Solution
{
    public:
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

    
    
//Reverse level order traversal    
//Using Vector    
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
//Using Stack
vector<int> reverseLevelOrder(Node *node)
{
     vector<int> ans;
      if(!node) return ans;
    
      queue<Node*> q;
      q.push(node);
      
      while(!q.empty()){
        stack<int> st;
          int n = q.size();
          for(int i=0;i<n;i++){
              Node* curr = q.front(); q.pop();
              
              st.push(curr->data);
              if(curr->left)
                q.push(curr->left);
             if(curr->right)
                q.push(curr->right);
          }
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
Expected Time Complexity: O(N)
    
    
     
  // Zigzag level order traversal    
 class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(!root) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
        
    	int k=0;
    	while(!q.empty()){
    	    int n = q.size();
    	    vector<int> v;
    	    for(int i=0;i<n;i++){
    	        Node* curr = q.front();q.pop();
                
    	        v.push_back(curr->data);
    	        if(curr->left)
    	            q.push(curr->left);
    	       if(curr->right)
    	            q.push(curr->right);
    	    }
    	    if(k%2==1)
    	        reverse(v.begin(),v.end());
    	    for(auto x:v)
    	        ans.push_back(x);
    	    k++;
    	}
    	return ans;
    }
};
Expected Time Complexity: O(N).
    
    
    
//Vertical Traversal
//Using Hashing
 vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
    
        queue<pair<Node*,int>> q;
        map<int,vector<int>>m;
    
        q.push({root,0});
    
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto p = q.front();q.pop();
                Node* curr = p.first;
                int hd = p.second;
                
                m[hd].push_back(curr->data);
                if(curr->left)
                q.push({curr->left,hd-1});
                if(curr->right)
                q.push({curr->right,hd+1});
            }
        }
        
        for(auto x:m){
            vector<int> temp = x.second;
            for(auto y:temp)
                ans.push_back(y);
        }
        return ans;
        
    }
};
Expected Time Complexity: O(N)
    
    
    
    
 // Diagonal Traversal
//Using Preorder and Hashing
void preorder(Node* root,map<int,vector<int>> &m,int d){
    if(!root) return;
    
    m[d].push_back(root->data);
    if(root->left)
        preorder(root->left,m,d+1);
    if(root->right)
        preorder(root->right,m,d);
}
vector<int> diagonal(Node *root)
{
   map<int,vector<int>>m;
   int d = 0;
   preorder(root,m,d);
   
   vector<int> ans;
   for(auto x:m){
       for(auto y:x.second)
        ans.push_back(y);
   }
   return ans;
}
Expected Time Complexity: O(N).
    
    
