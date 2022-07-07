ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        ListNode* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
