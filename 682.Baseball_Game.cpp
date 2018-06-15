class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto s:ops){
            if(s=="+"){
                v.push_back(v.back()+v[v.size()-2]);
            }else if(s=="D"){
                v.push_back(2*v.back());
            }else if(s=="C"){
                v.pop_back();
            }else{
                v.push_back(stoi(s));
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
