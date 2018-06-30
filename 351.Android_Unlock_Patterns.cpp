class Solution {
public:
    int solve(vector<vector<int>> & jumps, vector<bool> & visited, int m, int n, int num, int len, int res){
        if(len>=m) res++;
        len++;
        if(len>n) return res;
        visited[num]=true;
        for(int i=1;i<=9;i++){
            if(!visited[i] && (jumps[num][i]==0 || visited[jumps[num][i]])){
                res=solve(jumps, visited, m, n, i, len, res);
            }
        }
        visited[num]=false;
        return res;
    }
    
    int numberOfPatterns(int m, int n) {
        int res=0;
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3]=jumps[3][1]=2;
        jumps[4][6]=jumps[6][4]=5;
        jumps[7][9]=jumps[9][7]=8;
        jumps[1][7]=jumps[7][1]=4;
        jumps[2][8]=jumps[8][2]=5;
        jumps[3][9]=jumps[9][3]=6;
        jumps[1][9]=jumps[9][1]=jumps[3][7]=jumps[7][3]=5;
        res+=solve(jumps, visited, m, n, 1, 1, 0)*4;
        res+=solve(jumps, visited, m, n, 2, 1, 0)*4;
        res+=solve(jumps, visited, m, n, 5, 1, 0);
        return res;
    }
};
