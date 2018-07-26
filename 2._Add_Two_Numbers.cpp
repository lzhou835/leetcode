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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * p=l1;
        ListNode * q=l2;
        ListNode * ret=NULL;
        ListNode * k;

        int result=(l1->val+l2->val)%10;
        int addon=(l1->val+l2->val)/10;
        p=p->next;
        q=q->next;

        ret=new ListNode(result);
        k=ret;

        while(p!=NULL && q!=NULL)
        {
            result=(p->val+q->val+addon)%10;
            addon=(p->val+q->val+addon)/10;
            k->next= new ListNode(result);
            k=k->next;
            p=p->next;
            q=q->next;
        }

        while(p!=NULL)
        {
            result=(p->val+addon)%10;
            addon=(p->val+addon)/10;
            k->next=new ListNode(result);
            k=k->next;
            p=p->next;
        }

        while(q!=NULL)
        {
            result=(q->val+addon)%10;
            addon=(q->val+addon)/10;
            k->next=new ListNode(result);
            k=k->next;
            q=q->next;
        }
	if(addon>0)
        {
            k->next=new ListNode(addon);
        }

        return ret;
    }
};
                             
