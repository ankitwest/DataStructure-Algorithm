class Solution{
  public:
    unordered_map<Node*,Node*> parent;

    Node* storeParentAndReturnTarget(Node* root,int target){
        Node* t;
        if(!root) return NULL;
        parent[root]=NULL;
    
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right] = curr;
            }
            if(curr->data==target){
                t=curr;
            }
        } 
        return t;
    }
    
    int sum_at_distK(Node* root, int target, int k){
        Node* t = storeParentAndReturnTarget(root,target);
    
        if(!t) return 0;
        queue<Node*>q;
        set<Node*>s;
        q.push(t);
        s.insert(t);
        int level=0; int sum=0;

        while(!q.empty()){
           int sz = q.size();
           if(level>k) break;
           for(int i = 0; i < sz; i++){
                 Node* curr = q.front(); q.pop();
                 sum += curr->data;
                 if(curr->left and s.find(curr->left)==s.end()){
                    q.push(curr->left);
                    s.insert(curr->left);
                 }
                 if(curr->right and s.find(curr->right)==s.end()){
                    q.push(curr->right);
                    s.insert(curr->right);
                 }
                 if(parent[curr] and s.find(parent[curr])==s.end()){
                    q.push(parent[curr]);
                    s.insert(parent[curr]);
                 }
           }
           level++;
        }
        return sum;
    }
};

Expected Time Complexity: O(N)
