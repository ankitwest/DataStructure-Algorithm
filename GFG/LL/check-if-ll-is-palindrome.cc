class Solution{
    public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(!head or !head->next) return true;
        
       auto midd = [](Node* x){
           Node* slow = x; Node* fast = x;
            while(fast->next and fast->next->next){
            slow = slow->next;
             fast = fast->next->next;
            }
            return slow;
       };
       
       auto reverse = [&](Node* x){
           Node* prev = NULL;
           Node* curr = x;
           Node* next;
           while(curr){
               next = curr->next;
               curr->next = prev;
               prev = curr;
               curr = next;
           }
           return prev;
       };
       Node* mid = midd(head);
       Node* b = reverse(mid->next);
       mid->next = NULL;
       Node* a = head;
       
       auto check = [&](Node* a,Node* b){
           while(a and b){
               if(a->data!=b->data)return false;
               a = a->next; b = b->next;
           }
           return true;
       };
      return check(head,b);
    }
};

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
