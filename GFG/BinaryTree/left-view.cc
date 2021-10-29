
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
