class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt=0;
        set<char> s(J.begin(),J.end());
        for(auto a:S) if(s.count(a)) cnt++;
        return cnt;
    }
};
