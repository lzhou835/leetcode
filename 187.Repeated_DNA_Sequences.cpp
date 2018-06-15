class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int val=0, i=0;
        while(i<9) val= val<<3 | (s[i++] & 7);
        while(i<s.size()){
            val= (val & 0x7ffffff) << 3 | (s[i++] & 7);
            if(st.count(val)) res.insert(s.substr(i-10, 10));
            else st.insert(val);
        }
        return vector<string>(res.begin(), res.end());
    }
};
