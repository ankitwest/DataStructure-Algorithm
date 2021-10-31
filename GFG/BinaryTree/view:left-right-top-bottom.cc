
//Left View

class Solution{
  public:
  vector<int> leftView(Node *root)
  {
   vector<int>v ;
   if(!root) return v;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       for(int i=0;i<n;i++){
           Node* curr = q.front(); q.pop();
           
           if(i==0) v.push_back(curr->data);
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
   }
   return v;
  }
};


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
  
  
  
  
    //Right View
  
  class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
    vector<int> v;
      
    if (root == NULL) return v;
        
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
    int n=q.size();
      for(int i=0;i<n;i++){     
          Node* curr = q.front();   q.pop();

          if(i == n-1) 
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


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
  
  
  
  
  //Top View
  
  class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> v;
        if(root==NULL) return v;
      
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
      
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            auto p = q.front();q.pop();
            Node* node = p.first;
            int hd = p.second;
            
             if(m.find(hd)==m.end())
                 m[hd]=curr->data;
            if(node->left) 
                q.push({node->left,hd-1});
            if(node->right) 
                q.push({node->right,hd+1});
        }
    }
    
    for(auto x:m){
        // cout<<x.first<<" "<<x.second<<endl;
        v.push_back(x.second);
    }
    return v;
    }
};


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
  
  
  
  
  // Bottom View
  
  class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> v;
       if(!root) return v;
       
       map<int,int> m;
       queue<pair<Node*,int>> q;
       q.push({root,0});
       while(!q.empty()){
           int n = q.size();
           for(int i=0;i<n;i++){
               auto p = q.front();q.pop();
               Node* curr = p.first;
               int hd = p.second;
               
               m[hd]= curr->data;
               if(curr->left)
                q.push({curr->left,hd-1});
                if(curr->right)
                q.push({curr->right,hd+1});
                
           }
       }
       for(auto x:m){
           v.push_back(x.second);
       }
       return v;
       
    }
};


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

