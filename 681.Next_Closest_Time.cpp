class Solution {
public:
    string nextClosestTime(string time) {
        string ret="0000";
        int index=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
        vector<int> tmp{600, 60, 10, 1};
        for(int i=1;i<=1440;i++)
        {
            int next=(index+i)%1440;
            int j=0;
            for(j=0;j<4;j++)
            {
                ret[j]='0'+next/tmp[j];
                next=next%tmp[j];
                if(time.find(ret[j])==string::npos) break;
            }
            if(j==4) break;
        }

        return ret.substr(0,2)+":"+ret.substr(2);
    }
};
