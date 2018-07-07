class Solution {
public:
    int getroot(int i, vector<int> & root){
        return root[i]==i?i:getroot(root[i], root);
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size(), ret=n;
        vector<int> root(n);
        for(int i=0;i<n;i++) root[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]==1){
                    int p1=getroot(i, root);
                    int p2=getroot(j, root);
                    if(p1!=p2){
                        ret--;
                        root[p2]=p1;
                    }
                }
            }
        }
        return ret;
    }
};

