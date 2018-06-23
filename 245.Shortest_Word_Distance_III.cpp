class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res=INT_MAX, p1=-1, p2=-1;
        for(int i=0;i<words.size();i++){
            int pre=p1;
            if(words[i]==word1) p1=i;
            if(words[i]==word2) p2=i;
            if(p1!=-1 && p2!=-1){
                if(word1==word2 && pre!=-1 && pre!=p1){
                    res=min(res, abs(pre-p1));
                }else if(p1 != p2){
                    res=min(res, abs(p1-p2));
                }
            }
        }
        return res;
    }
};
