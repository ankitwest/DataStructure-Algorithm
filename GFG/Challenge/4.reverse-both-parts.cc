
class Solution{
public:
    Node* reverseFun(Node* head){
        Node* prev = nullptr; Node* curr = head;
        Node* next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *reverse(Node *head, int k)
    {
        
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        prev->next = head;
        
        while(k--)
            prev = prev->next;
            
        Node* s = reverseFun(prev->next);
        prev->next = NULL;
        Node* f = reverseFun(dummy->next);
        
        Node* temp = f;
        while(temp->next)
            temp = temp->next;
        
        temp->next = s;
        
        return f;
    }
    };
