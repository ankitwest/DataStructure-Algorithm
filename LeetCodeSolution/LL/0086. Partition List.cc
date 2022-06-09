

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0); ListNode* dummy2 = new ListNode(0);
        auto pre = dummy1; auto post = dummy2;
        
        while(head){
            if(head->val<x)
                pre->next = head,pre = pre->next;
            else
                post->next = head,post = post->next;
            head = head->next;
        }
        post->next = nullptr;
        pre->next = dummy2->next;
        
        return dummy1->next;
    }
};

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
