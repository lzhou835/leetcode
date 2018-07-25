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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2 || head==NULL) return head;
        ListNode * tmp=new ListNode(0);
        tmp->next=head;

        ListNode * p=tmp;
        while(p->next&&p->next->next)
        {
            int count=0;
            ListNode * slow=p->next;
            ListNode * fast=p->next->next;
            while(count<k-1 && fast)
            {
                ListNode * t=fast->next;
                fast->next=slow;
                slow=fast;
                fast=t;
                count++;
            }
            if(count==k-1)
            {
                ListNode * t=p->next;
                t->next=fast;
                p->next=slow;
                p=t;
            }else{
                fast=slow->next;
                slow->next=NULL;
                while(fast!=p->next)
                {
                    ListNode * t=fast->next;
                    fast->next=slow;
                    slow=fast;
                    fast=t;
                }
                break;
            }
        }
        ListNode * ret=tmp->next;
        delete tmp;
        return ret;
    }
};

