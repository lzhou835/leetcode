class Solution {
public:
    bool isvalid(vector<int> & pos, int row, int col){
        for(int i=0;i<row;i++){
            if(pos[i]==col || abs(col-pos[i])==abs(row-i)) return false;
        }
        return true;
    }

    void solve(vector<vector<string>> & res, vector<int> & pos, int row){
        int n=pos.size();
        if(row==n){
            vector<string> tmp(n, string(n, '.'));
            for(int i=0;i<n;i++){
                tmp[i][pos[i]]='Q';
            }
            res.push_back(tmp);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        solve(res, pos, 0);
        return res;
    }
};

