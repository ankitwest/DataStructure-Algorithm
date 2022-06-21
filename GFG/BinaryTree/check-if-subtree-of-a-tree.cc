class Solution1
{
    //Function to check if S is a subtree of tree T.
    bool identical(Node* r1,Node* r2){
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        
        if(r1->data != r2->data) return false;
        
        return (r1->data==r2->data) and identical(r1->left,r2->left) and identical(r1->right,r2->right);
    }
public:
    bool isSubTree(Node* T, Node* S) 
    {
       queue<Node*> q;
       q.push(T);
       while(!q.empty()){
           auto curr = q.front();q.pop();
           if(curr->data==S->data) {
               if(identical(curr,S))
                return true;
           }
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       return false;
    }
};





class Solution
{
    //Function to check if S is a subtree of tree T.
    bool identical(Node* r1,Node* r2){
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        
        if(r1->data != r2->data) return false;
        
        return (r1->data==r2->data) and identical(r1->left,r2->left) and identical(r1->right,r2->right);
    }
public:
    bool isSubTree(Node* T, Node* S) 
    {
      if(!T and !S) return true;
      if(!T or !S) return false;
        
      if(identical(T,S)) return true;
      
      return isSubTree(T->left,S) or isSubTree(T->right,S);
    }
};



Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 
Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.
