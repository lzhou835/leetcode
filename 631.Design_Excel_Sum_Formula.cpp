class Excel {
public:
    Excel(int H, char W) {
        m.clear();
        mat.resize(H, vector<int>(W-'A', 0));
    }
    
    void set(int r, char c, int v) {
        if(m.count({r,c})) m.erase({r,c});
        mat[r-1][c-'A']=v;
    }
    
    int get(int r, char c) {
        if(m.count({r,c})) return sum(r, c, m[{r,c}]);
        return mat[r-1][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int res=0;
        for(string s:strs){
            auto found=s.find_last_of(":");
            if(found==string::npos){
                char y=s[0];
                int x=stoi(s.substr(1));
                res+=get(x,y);
            }else{
                int y1=s[0]-'A', x1=stoi(s.substr(1, (int)found-1));
                int y2=s[found+1]-'A', x2=stoi(s.substr(found+2));
                for(int i=x1;i<=x2;i++){
                    for(int j=y1;j<=y2;j++){
                        res+=get(i, j+'A');
                    }
                }
            }
        }
        m[{r,c}]=strs;
        return res;
    }
private:
    vector<vector<int>> mat;
    map<pair<int, char>, vector<string>> m;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
