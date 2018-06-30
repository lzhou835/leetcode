class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto w:dictionary){
            string k=w[0]+to_string(w.size()-2)+w.back();
            m[k].insert(w);
        }
    }
    
    bool isUnique(string word) {
        string k=word[0]+to_string(word.size()-2)+word.back();
        return m[k].count(word)==m[k].size();
    }
private:
    unordered_map<string, set<string>> m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
