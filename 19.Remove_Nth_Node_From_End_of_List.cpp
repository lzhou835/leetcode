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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast=head;
        ListNode * slow=head;
        int count=0;

        while(count<n && fast!=NULL)
        {
            fast=fast->next;
            count++;
        }

        if(count==n && fast==NULL)
        {
            head=head->next;
            delete slow;
            return head;
        }

        while(fast->next != NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        ListNode * tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        return head;
    }
};

