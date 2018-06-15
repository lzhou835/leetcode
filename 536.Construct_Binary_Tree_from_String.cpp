/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        auto found=s.find('(');
        int val=(found==string::npos)?stoi(s):stoi(s.substr(0, found));
        TreeNode * node=new TreeNode(val);
        if(found==string::npos) return node;
        int start=found, cnt=0;
        for(int i=start;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            if(cnt==0 && start==found){
                node->left=str2tree(s.substr(start+1, i-start-1));
                start=i+1;
            }else if(cnt==0){
                node->right=str2tree(s.substr(start+1, i-start-1));
            }
        }
        return node;
    }
};
