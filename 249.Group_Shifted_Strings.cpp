class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> m;
        for(auto a:strings){
            string t="";
            for(auto c:a){
                t+=to_string((c+26-a[0])%26)+",";
            }
            m[t].insert(a);
        }
        for(auto a:m){
            res.push_back(vector<string>(a.second.begin(),a.second.end()));
        }
        return res;
    }
};
