class LFUCache {
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        freq[m[key].second].erase(it[key]);
        m[key].second++;
        freq[m[key].second].push_back(key);
        it[key]=--freq[m[key].second].end();
        if(freq[minfre].size()==0) minfre++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        if(get(key)!=-1){
            m[key].first=value;
            return;
        }
        
        if(m.size()>=cap){
            m.erase(freq[minfre].front());
            it.erase(freq[minfre].front());
            freq[minfre].pop_front();
        }
        m[key]={value, 1};
        minfre=1;
        freq[minfre].push_back(key);
        it[key]=--freq[minfre].end();
    }
private:
    int cap, minfre;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> it;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
