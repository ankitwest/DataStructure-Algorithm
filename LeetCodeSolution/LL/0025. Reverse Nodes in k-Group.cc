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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* temp = dummy;
        
        int count = 0;
        while(temp){
            temp = temp->next;
            count = count + 1;
        }
        
        ListNode* prev = dummy;ListNode* curr = dummy; ListNode* next = dummy;
        while(next){
            curr = prev->next;
            next = curr->next;
            
            int kk = (count>k) ? k : 0;
            for(int i=1;i<kk;i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }
        
        return dummy->next;
    }
};

/*
[1,2,3,4,5]
3
int kk = count>k?k:0;
Ans-[3,2,1,4,5]

int kk = count>k?k:count-1;
Ans-[3,2,1,5,4]
*/
