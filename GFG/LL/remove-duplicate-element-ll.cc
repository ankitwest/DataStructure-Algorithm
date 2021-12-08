
// Sorted list
class Solution
{
    public:
    Node *removeDuplicates(Node *head)
    {
        if(!head) return NULL;

         Node* curr = head;
        //  Node* temp = NULL;
         while(curr->next!=NULL){
             if(curr->next->data == curr->data){
                //  temp = curr->next;
                 curr->next = curr->next->next;
                //  delete temp;
             }
             else curr = curr->next;
         }
         return head;
    }
];


// Unsorted list
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(!head) return NULL;
        Node* curr = head;  
        unordered_map<int,int> m;
        m[curr->data]=1;
        while(curr->next!=NULL){
            int x = curr->next->data;
            if(m.find(x)!=m.end())
                curr->next = curr->next->next;
            else
                m[x]=1, curr = curr->next;
        }
        return head;
    }
};
