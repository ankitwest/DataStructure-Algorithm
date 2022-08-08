

struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

node* getTail(node* root){
    while(root and root->next){
        root = root->next;
    }
    return root;
}
node* partition(node* head,node *tail){
    node* pivot = head;  // pivot = 0;
    node* curr = head->next;
    node* prev = head;

    while(curr != tail->next){
        if(curr->data < pivot->data){  // if(a[k] < a[pivot])
            swap(prev->next->data,curr->data);  //swap(a[i+1], a[k])
            prev = prev->next;  // i += 1;
        }
        curr = curr->next;
    }
    swap(prev->data,pivot->data);  //swap(a[i],a[pivot])
    return prev;  //new pivot
}

node* quick_sort(node* head,node* tail){
    if(!head or head==tail)
    return NULL;
    //l < r
    
    node* pivot = partition(head,tail);
    quick_sort(head,pivot);
    quick_sort(pivot->next,tail);
}

void quickSort(struct node **headRef) {
    node *head = *headRef;
    if(!head or !head->next){
        return ;
    }
    node *tail = getTail(head);
    quick_sort(head, tail);
}
