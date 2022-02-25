
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
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* temp = new ListNode(0);
        ListNode* point = temp;
        while(l1 and l2){
            if(l1->val<=l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1){
             temp->next = l1;
             l1 = l1->next;
             temp = temp->next;
        }
         while(l2){
             temp->next = l2;
             l2 = l2->next;
             temp = temp->next;
        }
        return point->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            pre=slow,slow=slow->next,fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1,l2);
    }
};


usign merge sort for LL because it easy to implement in it
