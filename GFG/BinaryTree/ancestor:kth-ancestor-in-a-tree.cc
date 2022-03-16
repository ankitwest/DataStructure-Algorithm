int height(Node* root,int k,int node,int &ans){
    if(!root) return 0;
    if(root->data==node) return 1;
    
    int lf = height(root->left,k,node,ans);
    int rf = height(root->right,k,node,ans);
    
    if(lf==k or rf==k){
        ans = root->data;
    }
    
    if(lf) return lf+1;
    else if(rf) return rf+1;
    else return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    height(root,k,node,ans);
    return ans;
}



// M-2 Better

vector<int> ans;
void nodeToRoot(Node* root,int node,vector<int> temp){
    if(!root) return ;
    if(root->data==node){
        ans=temp;
        return;
    }
    
    temp.push_back(root->data);
    nodeToRoot(root->left,node,temp);
    nodeToRoot(root->right,node,temp);
    temp.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> temp;
    nodeToRoot(root,node,temp);
    if(ans.size()<k) return -1;
    
    return ans[ans.size()-k];
}


// M-3// parent approach
// M-3
void findPar(vector<int> &parent,Node* root){
    parent[root->data] = -1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front(); 
        q.pop();
        if(curr->left){
            parent[curr->left->data] = curr->data;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }
}
 int kthAncestor(Node *root, int k, int node)
{
    vector<int> parent(10005,0);
    findPar(parent,root);
    
    int cnt=0;
    while(node!=-1){
        node = parent[node];
        cnt++;
        if(cnt==k)
            return node;
    }
    return -1;
}


  
