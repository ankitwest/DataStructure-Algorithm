class Solution
{
    public:  
    Node* reverseBetween(Node* head, int l, int r)
    {
       Node* dummy = new Node(0);
       Node* prev = dummy;  prev->next = head;
        for(int i=1;i<l;i++){
            prev = prev->next;
        }
        Node* tail = prev->next;

        for(int i=1;i<=r-l;i++){
            Node* temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};

Example:
5 2 4
1 7 5 3 9


// p tp&tl
// 1  7   5  3   9

// p tp  tl
// 1 5   7   3   9

// p tp      tl
// 1 3   5   7   9
