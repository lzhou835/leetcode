class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;

        ListNode * p=head;
        ListNode * q=head->next;

        while(q!=NULL)
        {
            if(p->val==q->val)
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }else{
                p=q;
                q=q->next;
            }
        }
        return head;
    }
};

