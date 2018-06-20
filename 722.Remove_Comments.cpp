class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string out="";
        bool blocked=false;
        for(auto str:source){
            for(int i=0;i<str.size();i++){
                if(!blocked){
                    if(i==str.size()-1) out+=str[i];
                    else{
                        string t=str.substr(i, 2);
                        if(t=="/*") blocked=true, i++;
                        else if(t=="//") break;
                        else out+=str[i];
                    }
                    
                }else{
                    if(i<str.size()-1){
                        string t=str.substr(i, 2);
                        if(t=="*/") blocked=false, i++;
                    }
                }
            }
            if(!out.empty()&&!blocked){
                res.push_back(out);
                out="";
            }
        }
        return res;
    }
};
