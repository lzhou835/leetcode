class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        unordered_map<char, int> dict;
        int left=0;
        int count=0;
        int minlen=s.length()+1;
        string ret="";

        for(int i=0;i<t.length();i++){
            if(dict.find(t[i])!=dict.end()){
                dict[t[i]]++;
            }else{
                dict[t[i]]=1;
            }
        }

        for(int right=0;right<s.length();right++){
            if(dict.find(s[right])!=dict.end()){
                dict[s[right]]--;
                if(dict[s[right]]>=0) count++;
                while(count==t.length()){
                    if(right-left+1<minlen){
                        minlen=right-left+1;
                        ret=s.substr(left, minlen);
                    }
                    if(dict.find(s[left])!=dict.end()){
                        dict[s[left]]++;
                        if(dict[s[left]]>0) count--;
                    }
                    left++;
                }
            }
        }
        return ret;
    }
};
