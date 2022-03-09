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
    ListNode* swapNodes(ListNode* head, int k) {
       int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int back = len-k;
        
        ListNode* right = head;
        ListNode* left = head;
        while(back--){
            right = right->next;
        }
        k--;
        while(k--){
            left = left->next;
        }
        swap(left->val,right->val);
        
        return head;
    }
     ListNode* swapNodes(ListNode* head, int k) {
         ListNode* kth = head, *ptr1 = head, *ptr2 = head;
         k--;
         while(k--){
             ptr1=ptr1->next;
         }
        kth = ptr1;
         ptr1=ptr1->next;
         
         while(ptr1){
             ptr1=ptr1->next;
             ptr2=ptr2->next;
         }
          swap(kth->val,ptr2->val);
         return head;
     }
};

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:
