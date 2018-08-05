class Solution {
public:
    bool isvalid(vector<int> & pos, int row, int col){
        for(int i=0;i<row;i++){
            if(pos[i]==col || abs(col-pos[i])==abs(row-i)) return false;
        }
        return true;
    }

    void solve(int & res, vector<int> & pos, int row){
        int n=pos.size();
        if(row==n){
            res++;
        }else{
            for(int i=0;i<n;i++){
                if(isvalid(pos, row, i)){
                    pos[row]=i;
                    solve(res, pos, row+1);
                    pos[row]=-1;
                }
            }
        }
    }

    int totalNQueens(int n) {
        int res=0;
        vector<int> pos(n, -1);
        solve(res, pos, 0);
        return res;
    }
};
