class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <=0 || numRows <=1) return s;

        string ret="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0, k=i;k<s.length();j++, k=(2*numRows-2)*j+i)
            {
                ret.append(1, s[k]);
                if(i==0 || i==numRows-1) continue;
                if(k+(numRows-i-1)*2<s.length())
                {
                    ret.append(1, s[k+(numRows-i-1)*2]);
                }
            }
        }
        return ret;
    }
};

