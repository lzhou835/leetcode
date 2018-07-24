/**
Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * tmp=new ListNode(0);
        tmp->next=head;
        ListNode * p=head;
        ListNode * q=tmp;

        while(p && p->next)
        {
            q->next=p->next;
            p->next=p->next->next;
            q->next->next=p;
            q=p;
            p=p->next;
        }
        ListNode * ret=tmp->next;
        delete tmp;
        return ret;
    }
};
