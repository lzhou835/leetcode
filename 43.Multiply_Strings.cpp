class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<1 || num2.length()<1) return "";

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int m=num1.length();
        int n=num2.length();

        string ret(m+n,'0');

        for(int i=0;i<n;i++)
        {
            int addon=0;
            int val=num2[i]-'0';
            for(int j=0;j<m;j++)
            {
                int tmp=val*(num1[j]-'0')+(ret[i+j]-'0')+addon;
                addon=tmp/10;
                ret[i+j]='0'+tmp%10;
            }
            if(addon!=0) ret[m+i]='0'+addon;
        }
        reverse(ret.begin(),ret.end());

        int count=0;
        while(count<(m+n-1) && ret[count]=='0') count++;
        ret.erase(0,count);

        return ret;
    }
};

