class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for(int i=0;i<sentences.size();i++){
            frq[sentences[i]]+=times[i];
        }
        data="";
    }

    vector<string> input(char c) {
        if(c=='#'){
            frq[data]++;
            data="";
            return {};
        }
        data.push_back(c);
        auto cmp=[](pair<string, int> & a, pair<string, int> & b){
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for(auto sen:frq){
            bool matched=true;
            for(int i=0;i<data.length();i++){
                if(data[i]!=sen.first[i]){
                    matched=false;
                    break;
                }
            }
            if(matched){
                q.push(sen);
                if(q.size()>3) q.pop();
            }
        }
        vector<string> res(q.size());
        for(int i=res.size()-1;i>=0;i--){
            res[i]=q.top().first;
            q.pop();
        }
        return res;
    }
private:
    unordered_map<string, int> frq;
    string data;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

