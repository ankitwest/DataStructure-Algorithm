

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// M-3
class Solution {
public:
     ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast and fast->next)
            slow = slow->next,fast = fast->next->next; 
         
        return slow;                                
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            auto nextNode = head->next;          
            head->next = prev;                   
            prev = head;                            
            head = nextNode;                        
        }
        return prev;                               
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next) return ;
        
        auto mid = middleNode(head);
        auto R = reverseList(mid);
        auto L = head->next;
        
        for(int i=0;L!=R;i++){
            if(i%2==0){
                head->next = R;
                R = R->next;
            }else{
                head->next = L;
                L = L->next;
            }
            head = head->next;
        }
    }
};

// M-2 
// with O(N) space using vector<ListNode*> arr;

// M-1
class Solution2 {
public:    // recursion
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return;
        
        ListNode* secondLast = head;
        while(secondLast->next and secondLast->next->next){
            secondLast = secondLast->next;
        }
        
        ListNode* temp = secondLast->next;
        secondLast->next->next = head->next;
        head->next = secondLast->next;
        
        secondLast->next = NULL;
        
        reorderList(head->next->next);
    }
};

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
