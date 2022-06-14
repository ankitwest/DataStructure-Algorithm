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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        if(!head) return nullptr;
        if(!head->next) return head;
        
        ListNode* prev = nullptr; ListNode* slow = head; ListNode* fast = head;
        
        while(fast and fast->next){
            prev = slow, slow = slow->next, fast = fast->next->next;
        }
        if(prev) prev->next = nullptr;
        
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
       ListNode* mid = findMid(head);
        
        TreeNode* curr = new TreeNode(mid->val);
        
        if(mid == head) return curr;
        
        curr->left = sortedListToBST(head);
        curr->right = sortedListToBST(mid->next);
        
        return curr;
    }
};
