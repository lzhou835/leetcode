/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode * dummy=new ListNode(-1);
        dummy->next=head;
        ListNode * newdummy=new ListNode(-1);
        ListNode * p=dummy, * q=newdummy;
        while(p->next){
            if(p->next->val<x){
                q->next=p->next;
                q=q->next;
                p->next=p->next->next;
                q->next=NULL;
            }else{
                p=p->next;
            }
        }
        q->next=dummy->next;
        return newdummy->next;
    }
};
