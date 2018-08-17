/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode * fast=head;
        ListNode * slow=head;
        ListNode * pre=slow;
        while(fast->next && fast->next->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        pre->next=NULL;
        TreeNode * ret=new TreeNode(slow->val);
        if(slow!=head) ret->left=sortedListToBST(head);
        ret->right=sortedListToBST(fast);
        return ret;
    }
};

