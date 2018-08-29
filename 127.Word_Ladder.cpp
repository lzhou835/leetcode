class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string, int> m;
        m[beginWord]=1;
        q.push(beginWord);
        while(!q.empty()){
            string word=q.front();
            q.pop();
            for(int i=0;i<word.size();i++){
                string newword=word;
                for(char c='a'; c<='z';c++){
                    newword[i]=c;
                    if(dict.count(newword) && newword==endWord) return m[word]+1;
                    if(dict.count(newword) && m.find(newword)==m.end()){
                        m[newword]=m[word]+1;
                        q.push(newword);
                    }
                }
            }
        }
        return 0;
    }
};
