class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string ret, token;
        vector<string> v;
        while(getline(ss, token, '/')){
            if(token==""||token==".") continue;
            else if(token==".." && !v.empty()) v.pop_back();
            else if(token!="..") v.push_back(token);
        }
        for(string s:v) ret+="/"+s;
        return v.empty()?"/":ret;
    }
};
