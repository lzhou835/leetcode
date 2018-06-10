/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> m;
        RandomListNode * res=new RandomListNode(head->label);
        m[head]=res;
        RandomListNode * p=res;
        RandomListNode * q=head;
        
        while(q->next){
            p->next=new RandomListNode(q->next->label);
            m[q->next]=p->next;
            p=p->next;
            q=q->next;
        }
        
        p=res;
        q=head;
        while(p){
            p->random=m[q->random];
            p=p->next;
            q=q->next;
        }
        
        return res;
    }
};
