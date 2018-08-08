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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n=1;
        ListNode * cur=head;
        while(cur->next){
            n++;
            cur=cur->next;
        }
        int m=n-k%n;
        cur->next=head;
        for(int i=0;i<m;i++) cur=cur->next;
        ListNode * newhead=cur->next;
        cur->next=NULL;
        return newhead;
    }
};

