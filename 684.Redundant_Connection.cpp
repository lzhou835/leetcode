class Solution {
public:
    int find(vector<int> root, int i){
        while(root[i]!=-1){
            i=root[i];
        }
        return i;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2001, -1);
        for(auto e:edges){
            int x=find(root, e[0]), y=find(root, e[1]);
            if(x==y) return e;
            root[x]=y;
        }
        return {};
    }
};
