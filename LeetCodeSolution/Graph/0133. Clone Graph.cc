/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

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
