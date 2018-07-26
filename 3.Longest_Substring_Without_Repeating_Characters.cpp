class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;

        int maxlen=1;
        int locallen=1;
        map<char, int> location;
        location[(s[0])]=0;

        for (int i=1;i<s.length();i++)
        {
            int last_seen=-1;
            if(location.count(s[i])>0)
            {
                last_seen=location[(s[i])];
            }
            location[(s[i])]=i;

            int firstloc=i-locallen;
            if(firstloc<=last_seen)
            {
                locallen=i-last_seen;
            }else{
                locallen++;
            }

            if(locallen>maxlen) maxlen=locallen;
        }
        return maxlen;
    }
};

