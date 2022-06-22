class Solution{
private:
    Node* middleNode(Node* node){
        Node* prev = NULL; Node* slow = node; Node* fast = node->next;
        
        while(fast and fast->next){
            prev = slow;slow = slow->next;fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* A, Node* B){
        Node* head = new Node(-1);
        Node* temp = head;
        
         while(A and B){
            if(A->data < B->data){
                temp->next = A;
                A = A->next;
                temp = temp->next;
            }
            else{
                temp->next = B;
                B = B->next;
                temp = temp->next;
            }
        }
        while(A){
            temp->next = A;
            A = A->next;
            temp = temp->next;
        }
        while(B){
            temp->next = B;
            B = B->next;
            temp = temp->next;
        }
        return head->next;
    }
 public: 
  //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head or !head->next)
            return head;
        
        Node* mid = middleNode(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        Node* A = mergeSort(left);
        Node* B = mergeSort(right);
        
        Node* C = merge(A, B);
        
        return C;
    }
};

N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
