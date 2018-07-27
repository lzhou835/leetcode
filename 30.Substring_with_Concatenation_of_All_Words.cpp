class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;

        if(words.size()==0) return ret;

        int len=words.size();
        int width=words[0].length();
        if(width*len>s.length()) return ret;

        map<string, int> words_map;

        for(int i=0;i<words.size();i++)
            words_map[words[i]]++;

        for(int i=0;i<=s.length()-width*len;i++)
        {
            if(check(i, s, words_map, len, width))
            {
                ret.push_back(i);
            }
        }

        return ret;
    }

    bool check(int start, string & s, map<string, int> & words_map, int len, int width){
        bool match=true;
        map<string, int> tmp;

        for(int i=0;i<len;i++)
        {
            string str=s.substr(start+i*width, width);
            if(words_map.count(str)==0) return false;
            tmp[str]++;
            if(tmp[str]>words_map[str]) return false;
        }
        return match;
    }
};
