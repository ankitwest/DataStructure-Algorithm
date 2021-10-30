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
