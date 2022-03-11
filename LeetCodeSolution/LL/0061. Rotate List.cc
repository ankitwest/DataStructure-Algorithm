class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        if(k==0) return head;
        
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(k%len==0) return head;
        
        k = k>len?k%len:k;
        ListNode* curr = head;
        ListNode* prev = head;
        while(k--){
            curr = curr->next;
        }
        while(curr and curr->next){
             curr = curr->next;
            prev = prev->next;
        }
        ListNode* next = prev->next;
        prev->next = NULL;
        curr->next = head;        
        return next;
    }
};


// M-2

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head or !head->next) return head;
        if(k==0) return head;
        
        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        if(k%len==0) return head;
        
        k = len - k%len;
        temp->next = head;
        while(k--){
             temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
