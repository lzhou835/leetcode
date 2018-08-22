class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;

        ListNode * tmp=new ListNode(0);
        tmp->next=head;

        ListNode * p=tmp;
        ListNode * q=head;

        while(q!=NULL)
        {
            if(q->next && q->next->val==q->val)
            {
                int value=q->val;
                while(q && q->val==value)
                {
                    p->next=q->next;
                    delete q;
                    q=p->next;
                }
            }else{
                p=q;
                q=q->next;
            }
        }

        head=tmp->next;

        return head;
    }
};
