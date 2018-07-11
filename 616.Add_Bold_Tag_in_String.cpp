class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string ret="";
        int n=s.length();
        int end=0;
        vector<bool> flag(n, false);
        for(int i=0;i<n;i++)
        {
            for(string word:dict){
                if(end<=n && s.substr(i, word.length())==word) end=max(end, (int)(i+word.length()));
            }
            flag[i]=end>i;
        }

        for(int i=0;i<n;i++){
            if(!flag[i]){
                ret+=s[i];
                continue;
            }
            int j=i;
            while(j<n && flag[j]) j++;
            ret+="<b>"+s.substr(i, j-i)+"</b>";
            i=j-1;
        }

        return ret;
    }
};

