class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        string value="";

        if(digits.length()>0)
        solve(0,digits,value,ret,table);

        return ret;
    }

    void solve(int pos, string & digits, string & value, vector<string> & ret,string table[]){
        if(value.length()==digits.length())
        {
            ret.push_back(value);
            return;
        }

        int index=digits[pos]-'0';
        for(int i=0;i<table[index].length();i++)
        {
            string newvalue=value;
            newvalue.append(1, table[index][i]);
            solve(pos+1,digits,newvalue,ret,table);
        }
    }
};

