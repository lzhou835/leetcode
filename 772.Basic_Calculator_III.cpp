class Solution {
public:
    int calculate(string s) {
        int n=s.size(), curres=0, res=0, num=0;
        char op='+';
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c>='0' && c<='9'){
                num=num*10+c-'0';
            }else if(c=='('){
                int j=i, cnt=0;
                for(;i<n;i++){
                    if(s[i]=='(') cnt++;
                    if(s[i]==')') cnt--;
                    if(cnt==0) break;
                }
                num=calculate(s.substr(j+1, i-j-1));
            }
            if(c=='+' || c=='-' || c=='*' || c=='/' || i==n-1){
                switch(op){
                    case '+':curres+=num; break;
                    case '-':curres-=num; break;
                    case '*':curres*=num; break;
                    case '/':curres/=num; break;
                }
                if(c=='+' || c=='-' || i==n-1){
                    res+=curres;
                    curres=0;
                }
                op=c;
                num=0;
            }
        }
        return res;
    }
};
