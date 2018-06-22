class Solution {
public:
    int longestSubstring(string s, int k) {
        int res=0, i=0, n=s.size();
        while(i+k<=n){
            int m[26]={0};
            int mask=0, mxid=i;
            for(int j=i;j<n;j++){
                int t=s[j]-'a';
                m[t]++;
                if(m[t]<k) mask|=(1<<t);
                else mask &= (~(1<<t));
                if(mask==0){
                    res=max(res, j-i+1);
                    mxid=j;
                }
            }
            i=mxid+1;
        }
        return res;
    }
};
