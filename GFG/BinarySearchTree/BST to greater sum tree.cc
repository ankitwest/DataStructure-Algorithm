
class Solution
{
    public:
    int sum = 0;
    void revInorder(Node* root){
        if(!root) return ;
        
        revInorder(root->right);
        sum = sum + root->data;
        root->data = sum - root->data;
        revInorder(root->left);
    }
    void transformTree(struct Node *root)
    {
         revInorder(root);
    }
};


class Solution2 {
public:   
    void inorder(struct Node *root,vector<int>& temp){
        if(!root) return ;
        
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
    void getSum(vector<int>& temp,vector<int>&temp2){
        int sum = 0;
        int n = temp.size();
        for(int i=n-1;i>=0;i--){
            temp2[i] = sum;
            sum += temp[i];
        }
    }
    int ind = 0;
    void modifyTree(struct Node *root,vector<int>& temp2){
        if(!root) return ;
        
        modifyTree(root->left,temp2);
        root->data = temp2[ind++];
        modifyTree(root->right,temp2);
    }
    void transformTree(struct Node *root)
    {
        vector<int> temp;
        inorder(root,temp);
        vector<int> temp2(temp.size());
        getSum(temp,temp2);
        modifyTree(root,temp2);
    }
};



Input:
           2
         /    \
        1      6
              /  \
             3    7
Output: 18 16 13 7 0
Explanation:
Every node is replaced with the 
sum of nodes greater than itself. 
The resultant tree is:
               16
             /    \
           18       7
                  /   \
                 13    0
