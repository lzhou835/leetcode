class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> words;
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level=1, min_level=INT_MAX;
        
        while(!paths.empty()){
            vector<string> t=paths.front();
            paths.pop();
            if(t.size()>level){
                for(string w:words) dict.erase(w);
                words.clear();
                level=t.size();
                if(level>min_level) break;
            }
            
            string lastword=t.back();
            for(int i=0;i<lastword.size();i++){
                string newlastword=lastword;
                for(char ch='a';ch<='z';ch++){
                    newlastword[i]=ch;
                    if(!dict.count(newlastword)) continue;
                    words.insert(newlastword);
                    vector<string> newp=t;
                    newp.push_back(newlastword);
                    if(newlastword == endWord){
                        ret.push_back(newp);
                        min_level=level;
                    }else{
                        paths.push(newp);
                    }
                }
            }
        }
        
        return ret;
    }
};
