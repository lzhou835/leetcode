class Solution {
public:
    void dfs(vector<vector<char>> & board, vector<vector<bool>> & visited, int & vertical, int & horizontal, int i, int j){
        int m=board.size(), n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] ||  board[i][j]=='.') return;
        vertical|=i;
        horizontal|=j;
        visited[i][j]=true;
        dfs(board,visited, vertical, horizontal, i+1, j);
        dfs(board,visited, vertical, horizontal, i-1, j);
        dfs(board,visited, vertical, horizontal, i, j+1);
        dfs(board,visited, vertical, horizontal, i, j-1);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0) return 0;
        int m=board.size(), n=board[0].size();
        int res=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    int vertical=0, horizontal=0;
                    dfs(board, visited, vertical, horizontal, i, j);
                    if(vertical==i || horizontal==j) res++;
                }
            }
        }
        return res;
    }
};
