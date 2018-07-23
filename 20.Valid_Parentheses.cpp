class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                tmp.push(s[i]);
            }else{
                if(s[i]!=')' && s[i]!=']' && s[i]!='}') return false;
                if(tmp.empty() || tmp.top()=='('&&s[i]!=')' || tmp.top()=='['&&s[i]!=']' || tmp.top()=='{'&&s[i]!='}') return false;
                tmp.pop();
            }
        }
        return tmp.empty();
    }
};

