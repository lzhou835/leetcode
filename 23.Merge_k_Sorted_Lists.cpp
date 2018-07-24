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
    struct mycompare{
        bool operator()(ListNode * p, ListNode * q)
        {
            return p->val>q->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, mycompare> minheap;

        ListNode * ret=new ListNode(0);
        ListNode * p=ret;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]) minheap.push(lists[i]);
        }

        while(!minheap.empty())
        {
            p->next=minheap.top();
            p=p->next;
            minheap.pop();
            if(p->next) minheap.push(p->next);
        }

        ListNode * tmp=ret;
        ret=ret->next;
        delete tmp;
        return ret;
    }
};

