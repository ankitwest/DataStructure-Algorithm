class Solution {
  public:
      unordered_map<Node *,Node *> par;
      Node* tar;
      Node* solve(Node* root, int target)
      {
          queue<Node*>q;
          q.push(root);
          
          while(!q.empty())
          {
            Node* curr=q.front();
            q.pop();
            if(curr->data==target) tar=curr;
              if(curr->left)
              {
                 par[curr->left]=curr;
                 q.push(curr->left);
              }
              if(curr->right)
              {
                  par[curr->right]=curr;
                  q.push(curr->right);
              }
          }
      }
      
    int minTime(Node* root, int target) 
    {
        solve(root,target);
        
        queue<Node*>q;
        q.push(tar);
        
        unordered_set<Node *> vis;
        vis.insert(tar);
        
        // for(auto it = par.begin(); it!=par.end(); ++it) {
        //     cout << it->first->data << ' ' << it->second->data << '\n';
        // }
        
        int cnt = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                Node* curr=q.front();
                q.pop();

                if(par[curr] and !vis.count(par[curr])) {
                    vis.insert(par[curr]);
                    q.push(par[curr]);
                }
              
                if(curr->left and !vis.count(curr->left)) { 
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right and !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
            }
           cnt++;
        }
        return cnt - 1 ;
        
    }
};
