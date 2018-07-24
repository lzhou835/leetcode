class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string prefix="";

        solve(n, 0, 0, ret, prefix);

        return ret;
    }

    void solve(int n, int left, int right, vector<string> & ret, string & prefix)
    {
        if(left==n && right==n)
        {
            ret.push_back(prefix);
            return;
        }

        if(left<n)
        {
            prefix.push_back('(');
            solve(n, left+1, right, ret, prefix);
            prefix.pop_back();
        }
        if(right<left)
        {
            prefix.push_back(')');
            solve(n, left, right+1, ret, prefix);
            prefix.pop_back();
        }
    }
};

