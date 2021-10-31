   
class Solution
{
    public:
    //Function to check if two trees are identical.
  
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        if(r1->data != r2->data) return false;
        
        return (r1->data == r2->data) and isIdentical(r1->left,r2->left) and isIdentical(r1->right,r2->right);

    }
};