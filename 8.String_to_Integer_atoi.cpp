class Solution {
public:
    int myAtoi(string str) {
        long ret=0;
        bool end=false;
        bool negtive=false;

        for(int i=0;i<str.length();i++)
        {
                if(end==true && (str[i]<'0' || str[i]>'9')) break;

                if(str[i] == ' ') continue;


                if(str[i]=='+' || str[i]=='-')
                {
                        if(str[i]=='-') negtive=true;
                        end=true;
                        continue;
                }

                if(str[i]>='0' && str[i]<='9')
                {
                        if(ret>2147483647) break;

                        if(end==false) end=true;
                        ret=ret*10+str[i]-'0';
                        continue;
                }
                return 0;
        }

        ret=(negtive==false?ret:-ret);

        if(ret>2147483647) return 2147483647;
        if(ret<-2147483648) return -2147483648;

        return ret;
    }
};
