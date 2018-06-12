class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return atoi(tokens[0].c_str());
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" &&tokens[i]!="/"){
                s.push(atoi(tokens[i].c_str()));
            }else{
                int a=s.top(); s.pop();
                int b=s.top(); s.pop();
                if(tokens[i]=="+") s.push(b+a);
                if(tokens[i]=="-") s.push(b-a);
                if(tokens[i]=="*") s.push(b*a);
                if(tokens[i]=="/") s.push(b/a);
            }
        }
        return s.top();
    }
};
