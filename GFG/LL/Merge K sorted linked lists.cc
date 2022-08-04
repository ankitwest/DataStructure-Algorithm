class Solution{
    Node* merge1(Node* a,Node* b)
    {
        if(a==NULL)return b;
        if(b==NULL)return a;
        if(a->data<b->data)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
    }
    Node* merge(Node* a,Node* b)
    {
        if(a==NULL)return b;
        if(b==NULL)return a;
        
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        while(a and b){
            if(a->data<=b->data)
            {
                curr->next = a;
                a = a->next;
            }
            else
            {
                curr->next = b;
                b = b->next;
            }   
            curr = curr->next;
        }
        
        curr->next = (a) ? a : b;
        // while(a){
        //     curr->next = a;
        //     a = a->next;
        //     curr = curr->next;
        // }
        // while(b){
        //     curr->next = b;
        //     b = b->next;
        //     curr = curr->next;
        // }
        
        return dummy->next;
    }
 public:    
    Node * mergeKLists(Node *arr[], int k)
    {
        Node* v = NULL;
        for(int i=0;i<k;i++){
            v = merge(v,arr[i]);
        }
         return v;
    }
};
