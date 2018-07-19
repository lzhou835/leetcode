class Solution {
public:
    bool isMatch(string s, string p) {
         int m=s.length();
        int n=p.length();

        vector<vector<bool> > match(m+1, vector<bool>(n+1));

        for(int i=0;i<m+1;i++)
                for(int j=0;j<n+1;j++)
                        match[i][j]=false;

        match[0][0]=true;

        for(int i=0;i<m+1;i++)
        {
                for(int j=1;j<n+1;j++)
                {
                        if(p[j-1] !='.' && p[j-1] !='*')
                        {
                                if(i>=1 && s[i-1]==p[j-1] && match[i-1][j-1])
                                        match[i][j]=true;
                        }else if(p[j-1] == '.')
                        {
                                if(i>=1 && match[i-1][j-1])
                                        match[i][j]=true;
                        }else if(p[j-1] == '*' && j>=2){
                                if(match[i][j-2] || match[i][j-1]){
                                        match[i][j]=true;
                                }else if(i>=1 && match[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.')){
                                        match[i][j]=true;
                                }
                        }
                }
        }
        return match[m][n];
    }
};

