class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret="";
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]!='-'){
                if(ret.length()%(K+1)==K){
                    ret+='-';
                    ret+=toupper(S[i]);
                }else{
                    ret+=toupper(S[i]);
                }
            }
        }
        
        return string(ret.rbegin(),ret.rend());
    }
};
