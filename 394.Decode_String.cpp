class Solution {
public:
    string decodeString(string s) {
        string t="";
        int cnt=0;
        stack<int> num;
        stack<string> str; 
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                cnt=cnt*10+s[i]-'0';
            }else if(s[i]=='['){
                num.push(cnt);
                str.push(t);
                cnt=0;
                t.clear();
            }else if(s[i]==']'){
                int k=num.top();
                num.pop();
                for(int j=0;j<k;j++) str.top()+=t;
                t=str.top();
                str.pop();
            }else{
                t+=s[i];
            }
        }
        
        return t;
    }
};
