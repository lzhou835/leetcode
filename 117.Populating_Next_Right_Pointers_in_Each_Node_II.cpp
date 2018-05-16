/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * dummy=new TreeLinkNode(0), * high=root, * low=dummy;
        while(high){
            if(high->left){
                low->next=high->left;
                low=low->next;
            }
            if(high->right){
                low->next=high->right;
                low=low->next;
            }
            high=high->next;
            if(!high){
                high=dummy->next;
                low=dummy;
                dummy->next=NULL;
            }
        }
    }
};
