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
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a) return b;
        if(!b) return a;
        
        ListNode* start = NULL;
        
        if(a->val <= b->val){
            start = a;
            start->next = merge(a->next,b);
        }else{
            start = b;
            start->next = merge(a,b->next);
        }
        
        return start;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ans = merge(ans,lists[i]);
        }
        return ans;
    }
};



M-2  Priority Queue

class Solution {
public:
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
         
         priority_queue<int,vector<int>,greater<int>> pq;
         for(int i=0;i<lists.size();i++){
             ListNode* head = lists[i];
             while(head){
                 pq.push(head->val);
                 head = head->next;
             }
         }
         
         ListNode* start = new ListNode(0);
         ListNode* end = start;
         
         while(!pq.empty()){
             end->next = new ListNode(pq.top());
             pq.pop();
             end = end->next;
         }
         
         return start->next;
     }
};
  
  
