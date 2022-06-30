class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    
    //Preorder with marking
    void ser(Node* root,vector<int> &v){
        if(!root) {
            v.push_back(-1);
            return ;
        }
        
        v.push_back(root->data);
        ser(root->left,v);
        ser(root->right,v);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> v;
        ser(root,v);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
        int index = 0;
    Node * deSerialize(vector<int> &A)
    {
        if(index==A.size())
            return NULL;
        
        int val = A[index++];
        
        if(val==-1)
            return NULL;
        
        Node* root = new Node(val);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        
        return root;
    }
};
Expected Time Complexity: O(N).
