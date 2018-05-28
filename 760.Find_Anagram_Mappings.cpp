class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> imap;
        for(int i=0;i<B.size();i++) imap[B[i]]=i;
        for(int i=0;i<A.size();i++) res.push_back(imap[A[i]]);
        return res;
    }
};
