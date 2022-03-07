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
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        
        ListNode* ans = new ListNode(0);
        ListNode* point = ans;
        
        while(a and b){
            if(a->val<=b->val){
                ans->next = a;
                a = a->next;
            }else{
                 ans->next = b;
                b = b->next;
            }
            ans = ans->next;
        }
        
        while(a){
             ans->next = a;
             a = a->next;
             ans = ans->next;
        }
         while(b){
             ans->next = b;
             b = b->next;
             ans = ans->next;
        }
        
        return point->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = merge(list1,list2);
        return ans;
    }
};


// Recusion


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* result;
        
        if(l1->val<l2->val){
            result=l1;
            result->next=mergeTwoLists(l1->next,l2);
        }
        else{
             result=l2;
            result->next=mergeTwoLists(l1,l2->next);
        }
        
        return result;
    }
};
