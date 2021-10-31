
//level order traversal
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

    
    
//reverse level order traversal    
Using Vector    
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

Using Stack

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
    
    
    
    
    
  //zigzag level order traversal    
    
 class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
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
