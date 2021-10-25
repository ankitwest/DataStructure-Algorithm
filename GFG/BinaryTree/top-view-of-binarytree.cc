class Solution
{
    public:
    //Function to return a list of nodes visible from the top view  from left to right in Binary Tree.
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
            int h = p.second;
            if(m[h]==0) m[h]=node->data;
            if(node->left) q.push({node->left,h-1});
            if(node->right) q.push({node->right,h+1});
        }
    }
    
    for(auto x:m)
        v.push_back(x.second);

    return v;
    
    }

};
