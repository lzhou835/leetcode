class Solution {
public:
    bool isValid(string code) {
        stack<string> s;
        for(int i=0;i<code.size();i++){
            if(i>0 && s.empty()) return false;
            if(code.substr(i, 9) =="<![CDATA["){
                int j=i+9;
                i=code.find("]]>", j);
                if(i<0) return false;
                i=i+2;
            }else if(code.substr(i, 2)=="</"){
                int j=i+2;
                i=code.find(">",j);
                if(i<0) return false;
                string tag=code.substr(j, i-j);
                if(s.empty() || s.top()!=tag) return false;
                s.pop();
            }else if(code.substr(i, 1)=="<"){
                int j=i+1;
                i=code.find(">",j);
                if(i<0 || i==j || i-j>9) return false;
                for(int k=j;k<i;k++){
                    if(code[k]<'A' || code[k]>'Z') return false;
                }
                string tag=code.substr(j, i-j);
                s.push(tag);
            }
        }
        return s.empty();
    }
};
