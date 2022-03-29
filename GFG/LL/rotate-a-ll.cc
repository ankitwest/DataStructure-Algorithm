

class Solution{
  {
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* temp = head;
        Node* prev = NULL;
        int n = 0;
        while(temp){
            prev = temp;
            temp = temp->next;
            n++;
        }
        if(k==n) return head;
        
        prev->next = head;
        Node* point = head;
        prev = NULL;
        while(k--){
            prev = point;
            point = point->next;
        }
        
        prev->next = NULL;
        return point;
    }
};
