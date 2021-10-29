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
