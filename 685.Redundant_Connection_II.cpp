class Solution {
public:
    int getroot(vector<int> & root, int i){
        return i==root[i]?i:getroot(root, root[i]);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> root(n+1, 0), first, second;
        for(auto & e:edges){
            if(root[e[1]]==0){
                root[e[1]]=e[0];
            }else{
                first={root[e[1]], e[1]};
                second=e;
                e[1]=0;
            }
        }
        for(int i=0;i<=n;i++) root[i]=i;
        for(auto & e:edges){
            if(e[1]==0) continue;
            int x=getroot(root, e[0]), y=getroot(root, e[1]);
            if(x==y) return first.empty()?e:first;
            root[x]=y;
        }
        return second;
    }
};
