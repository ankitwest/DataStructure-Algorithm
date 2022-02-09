

class Solution
{
private:
public:
    void mark_parent(Node* root,unordered_map<Node*,Node*> &parent,int target,Node* &tgt){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            if(curr->data==target)
                tgt = curr;
            if(curr->left != NULL){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
                if(curr->right != NULL){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent; //make a parent map 
        Node* tgt = NULL;  // find the starting node
        mark_parent(root,parent,target,tgt);
        
        queue<Node*> q;
        unordered_map<Node*,bool> vis;
        
        q.push(tgt);
        vis[tgt]=true;
        
        while(!q.empty()){  // look for its children and also its parent
            int sz = q.size();
            while(sz--){
                Node* curr = q.front(); q.pop();
                if(parent[curr] and !vis[parent[curr]]){
                    q.push(parent[curr]); vis[parent[curr]]=true;
                }
                if(curr->left and !vis[curr->left]){
                     q.push(curr->left); vis[curr->left]=true;
                }
                if(curr->right and !vis[curr->right]){
                     q.push(curr->right);  vis[curr->right]=true;
                }
            }
            k--;
            if(k<=0) break;
        }
        
        vector<int> ans;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};




Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.
