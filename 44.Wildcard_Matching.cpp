class Solution {
public:
    bool isMatch(string s, string p) {

        int m=s.length();
        int n=p.length();

        bool match[m+1][n+1];
        memset(match, false, sizeof(match));

        match[0][0]=true;

        for(int i=0;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i>=1 && (s[i-1]==p[j-1] || p[j-1]=='?'))
                {
                    match[i][j]=match[i-1][j-1];
                }else if(p[j-1]=='*'){
                    if(match[i][j-1] || i>=1 && (match[i-1][j-1] || match[i-1][j]))
                        match[i][j]=true;
                }
            }
        }
        return match[m][n];
    }
};

