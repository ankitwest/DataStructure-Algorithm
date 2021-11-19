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
    Node* deS(vector<int> &A,int &curr){
        if(A[curr]==-1){
            curr++;
            return NULL;
        }
        Node* root = new Node(A[curr++]);
        
        root->left = deS(A,curr);
        root->right = deS(A,curr);
    
        return root;
    }
    Node * deSerialize(vector<int> &A)
    {
        int curr=0;
       return deS(A,curr);
    }
};
Expected Time Complexity: O(N).
