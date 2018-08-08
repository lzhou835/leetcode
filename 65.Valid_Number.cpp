class Solution {
public:
    bool isNumber(string s) {
        int left=0;
        int right=s.length()-1;
        while(s[left]==' ') left++;
        while(s[right]==' ') right--;

        bool flag_digit=false;
        bool flag_eE=false;
        bool flag_dot=false;

        if(left>=right && (s[left]<'0' || s[left]>'9')) return false;

        if(s[left]>='0' && s[left]<='9'){
            flag_digit=true;
        }else if(s[left]=='.'){
            flag_dot=true;
        }else if(s[left]!='+' && s[left]!='-'){
            return false;
        }

        for(int i=left+1;i<=right-1;i++){
            if(s[i]>='0' && s[i]<='9'){
                flag_digit=true;
            }else if(s[i]=='e' || s[i]=='E'){
                if(!flag_eE && s[i-1]!='+' && s[i-1]!='-' && flag_digit) flag_eE=true;
                else return false;
            }else if(s[i]=='+' || s[i]=='-'){
                if(s[i-1]!='e' && s[i-1]!='E') return false;
            }else if(s[i]=='.'){
                if(!flag_dot && !flag_eE) flag_dot=true;
                else return false;
            }else return false;
        }

        if(s[right]>='0' && s[right]<='9') return true;
        else if(s[right]=='.' && !flag_dot && !flag_eE && flag_digit) return true;
        else return false;
    }
};

