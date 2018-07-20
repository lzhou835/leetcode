class Solution {
public:
    int romanToInt(string s) {
        int intdir[13]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romandir[13]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV" ,"I"};
        int ret=0;
        int i=0;
        int pos=0;

        while(i<13 && pos<s.length())
        {
            string match=romandir[i];
            if(match == s.substr(pos,match.length()))
            {
                ret+=intdir[i];
                pos+=match.length();
            }else{
                i++;
            }
        }

        return ret;
    }
};

