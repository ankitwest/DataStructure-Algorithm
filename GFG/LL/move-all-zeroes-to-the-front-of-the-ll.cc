

void moveZeroes(struct Node **head)
{
    if((*head)==NULL) return ;
    
    Node* curr = (*head)->next; 
    Node* prev = *head;
    while(curr){
        if(curr->data==0){
            Node* temp = curr;
            
            curr = curr->next;
            prev->next = curr;
            
            temp->next = *head;
            *head = temp;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}



Input:  0 -> 4 -> 0 -> 5 -> 0
Output: 0 -> 0 -> 0 -> 4 -> 5
    

// // wrong
// void moveZeroes(struct Node **head)
// {
//     Node* num = new Node(0);
//     Node* ze = new Node(0);
    
//     Node* zeh = ze; Node* numh = num;
//     Node* curr = *head;
//     while(curr){
//         if(curr->data==0){
//             ze->next = curr;
//             ze = ze->next;
//         }else{
//             num->next = curr;
//             num = num->next;
//         }
//         curr = curr->next;
//     }
//     if(numh->next) ze->next = numh->next;
//     else ze->next = NULL;
//     if(zeh->next) *head = zeh->next;
    
// }
