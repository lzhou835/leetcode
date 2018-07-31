class Solution {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        string ret="1";
        int i=1;

        while(i<n)
        {
            int count=1;
            char num=ret[0];
            string local="";

            for(int j=1;j<ret.size();j++)
            {
                if(ret[j]==num)
                {
                    count++;
                }else{
                    char countstr='0'+count;
                    local.push_back(countstr);
                    local.push_back(num);
                    count=1;
                    num=ret[j];
                }
            }
            char countstr='0'+count;
            local.push_back(countstr);
            local.push_back(num);
            ret=local;

            i++;
        }

        return ret;
    }
};

