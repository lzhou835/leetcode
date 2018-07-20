class Solution {
public:
    string intToRoman(int num) {
        string ret="";

        int intdir[13]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romandir[13]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV" ,"I"};

        for(int i=0;i<13;i++)
        {
            while(num>=intdir[i])
            {
                ret+=romandir[i];
                num-=intdir[i];
            }
        }

        return ret;
    }
};
