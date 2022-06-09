class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    Node* reverse(Node* &curr){
        Node* prev = NULL;
        Node* nex = curr->next;
        
        curr->next = prev;
        while(nex){
            prev = curr;
            curr = nex;
            nex = nex->next;
            curr->next = prev;
        }
        return curr;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* curr = new Node(0); Node* dummy = curr;
        int cf=0;
        Node* l1 = reverse(first);
        Node* l2 = reverse(second);
        
        while(l1 or l2 or cf){
            cf += l1?(l1->data):0;
            cf += l2?(l2->data):0;
            
            curr->next = new Node(cf%10);
            cf /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            curr = curr->next;
        }
        
        return reverse(dummy->next);
    }
};
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
