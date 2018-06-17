class Solution {
public:
    void solve(string s, int & a, int & b, bool isleft){
        int sign=1, num=-1;
        s+="+";
        for(int i=0;i<s.size();i++){
            if(s[i]=='-' || s[i]=='+'){
                num=(num==-1)?0:(sign*num);
                a+=isleft?-num:num;
                num=-1;
                sign=(s[i]=='+')?1:-1;
            }else if(s[i]>='0' && s[i]<='9'){
                if(num==-1) num=0;
                num=num*10+s[i]-'0';
            }else if(s[i]=='x'){
                num=(num==-1)?sign:(sign*num);
                b+=isleft?num:-num;
                num=-1;
            }
        }
    }
    
    string solveEquation(string equation) {
        int a=0, b=0;
        auto p=equation.find("=");
        solve(equation.substr(0, p), a, b, true);
        solve(equation.substr(p+1), a, b, false);
        if(b==0 && a==b) return "Infinite solutions";
        if(b==0 && a!=b) return "No solution";
        return "x="+to_string(a/b);
    }
};
