/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void serFun(TreeNode* root,ostringstream &out){
        if(!root){
            out << "# ";
            return;
        }
        
        out << root->val << " ";
        serFun(root->left,out);
        serFun(root->right,out);
    }
    string serialize(TreeNode* root) {
        ostringstream out;
        serFun(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserFun(istringstream &in){
        string val;
        in >> val;
        
        if(val == "#")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserFun(in);
        root->right = deserFun(in);
        
        return root;
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserFun(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
