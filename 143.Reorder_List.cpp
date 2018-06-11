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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode * slow=head, * fast=head;
        while(fast->next &&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode * p=slow->next;
        slow->next=NULL;
        ListNode * pre=NULL;
        ListNode * q=NULL;
        while(p){
            q=p->next;
            p->next=pre;
            pre=p;
            p=q;
        }
        
        ListNode * cur=head;
        while(cur && pre){
            q=cur->next;
            cur->next=pre;
            pre=pre->next;
            cur->next->next=q;
            cur=q;
        }
    }
};
