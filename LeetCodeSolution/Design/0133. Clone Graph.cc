class Solution {
public:
    // unordered_map<Node*,Node*> vis;
    unordered_map<int,Node*> vis;
    
    Node* rec(Node* node){
        if(vis.find(node->val)!=vis.end())
            return vis[node->val];
        
        Node* ans = new Node(node->val);
        vis[node->val] = ans;
        
        for(auto child:node->neighbors){
            ans->neighbors.push_back(rec(child));
        }
        return ans;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        return rec(node);
    }
};
