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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * l3=new ListNode(0);
        ListNode * p=l3;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }else{
                p->next=l2;
                l2=l2->next;
            }
                p=p->next;
        }
        if(l1==NULL) p->next=l2;
        if(l2==NULL) p->next=l1;

        ListNode * tmp=l3;
        l3=l3->next;
        delete tmp;
        return l3;
    }
};
