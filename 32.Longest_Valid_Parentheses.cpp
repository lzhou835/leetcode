class Solution {
public:
    int longestValidParentheses(string s) {
        int ret=0;
        stack<pair<int, int> > tmp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                tmp.push(make_pair(i,0));
            }else{
                if(tmp.empty() || tmp.top().second==1)
                {
                    tmp.push(make_pair(i,1));
                }else{
                    tmp.pop();
                    int local=0;
                    if(tmp.empty())
                        local=i+1;
                    else
                        local=i-tmp.top().first;
                    ret=max(local,ret);
                }
            }
        }
        return ret;
    }
};

