class Solution {
public:
    string find(string s, unordered_map<string, string> & root){
        return root[s]==s?s:find(root[s], root);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ret;
        unordered_map<string, string> root;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> hmap;
        for(auto account:accounts){
            for(int i=1;i<account.size();i++){
                owner[account[i]]=account[0];
                root[account[i]]=account[i];
            }
        }
        
        for(auto account:accounts){
            string p=find(account[1], root);
            for(int i=2;i<account.size();i++){
                root[find(account[i],root)]=p;
            }
        }
        
        for(auto account:accounts){
            for(int i=1;i<account.size();i++){
                hmap[find(account[i],root)].insert(account[i]);
            }
        }
        
        for(auto m:hmap){
            vector<string> v(m.second.begin(),m.second.end());
            v.insert(v.begin(), owner[m.first]);
            ret.push_back(v);
        }
        
        return ret;
    }
};
