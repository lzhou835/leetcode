class Solution {
public:
    bool valid(string s){
        if(s.empty() || s.size()>3 || (s.size()>1 && s[0]=='0')) return false;
        int val=atoi(s.c_str());
        return val<=255 && val>=0;
    }
    
    void solve(string s, int k, string tmp, vector<string> & ret){
        if(k==0){
            if(s.size()==0) ret.push_back(tmp);
        }else{
            for(int i=1;i<=3;i++){
                if(s.size()>=i && valid(s.substr(0, i))){
                    if(k==1) solve(s.substr(i), k-1, tmp+s.substr(0, i), ret);
                    else solve(s.substr(i), k-1, tmp+s.substr(0, i)+".", ret);
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        solve(s, 4, "", ret);
        return ret;
    }
};
