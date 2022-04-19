

struct Node* partition(struct Node* head, int x) {
    Node* curr = head;
    if(!head) return NULL;
     Node* smaller = NULL;  Node* smaller_head = NULL; 
     Node* equal = NULL;  Node* equal_head = NULL;
     Node* greater = NULL;  Node* greater_head = NULL;
   
    while(curr){
        if(curr->data<x){
            if(!smaller) smaller = smaller_head = curr;
            else smaller->next = curr, smaller = smaller->next;
        }
        if(curr->data==x){
            if(!equal) equal = equal_head = curr;
            else equal->next = curr, equal = equal->next;
        }
        if(curr->data>x){
            if(!greater) greater = greater_head = curr;
            else greater->next = curr, greater = greater->next;
            // greater = greater -> next = head 
        }
        curr = curr->next;
    }
    
    if(greater){
        greater->next = NULL;
    }
    
    if(equal){
        equal->next = greater_head;
        greater_head = equal_head;
    }
    
    if(smaller){
        smaller->next = greater_head;
        greater_head = smaller_head;
    }
    
    return greater_head;
}


Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5
Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.
