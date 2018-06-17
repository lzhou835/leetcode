class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string, int> freq;
        auto cmp=[](pair<string, int> & a, pair<string, int> & b){
            return (a.second>b.second) || (a.second==b.second && a.first<b.first);
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for(auto w:words) freq[w]++;
        for(auto f:freq){
            q.push(f);
            if(q.size()>k) q.pop();
        }
        
        for(int i=q.size()-1;i>=0;i--){
            res[i]=q.top().first;
            q.pop();
        }
        
        return res;
    }
};
