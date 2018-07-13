class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        stack<int> s;
        int pretime=0;

        for(string log:logs)
        {
            int i1=log.find(':');
            int i2=log.find_last_of(':');
            int id=stoi(log.substr(0, i1));
            string type=log.substr(i1+1, i2-i1-1);
            int time=stoi(log.substr(i2+1));
            if(!s.empty()){
                ret[s.top()]+=time-pretime;
            }
            pretime=time;
            if(type=="start"){
                s.push(id);
            }else{
                int j=s.top();
                s.pop();
                ret[j]++;
                pretime++;
            }
        }
        return ret;
    }
};

