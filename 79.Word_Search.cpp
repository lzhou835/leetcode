class Solution {
public:
    bool dfs(vector<vector<char>> & board, string & word, int k, int i, int j, vector<vector<int>> & visited){
        if(k==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] || board[i][j]!=word[k]) return false;
        visited[i][j]=1;
        bool ret=dfs(board, word, k+1, i-1, j, visited) || dfs(board, word, k+1, i+1, j, visited) || dfs(board, word, k+1, i, j-1, visited) || dfs(board, word, k+1, i, j+1, visited);
        visited[i][j]=0;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.size()==0 || board[0].size()==0) return false;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                if(dfs(board, word, 0, i, j, visited)) return true;
            }
        return false;
    }
};

