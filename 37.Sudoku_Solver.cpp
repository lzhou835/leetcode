class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()<9 || board[0].size()<9) return;
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> > & board, int row, int col)
    {
        if(row==9) return true;
        int tmp=(row*9+col)+1;

        int nextrow=tmp/9;
        int nextcol=tmp%9;
        if(board[row][col]!='.')
        {
            if(!check(board, row, col)) return false;
            return solve(board, nextrow, nextcol);
        }

        for(int i=0;i<9;i++)
        {
            board[row][col]='0'+i+1;
            if(check(board, row, col) && solve(board, nextrow, nextcol)) return true;
        }
        board[row][col]='.';
        return false;
    }

    bool check(vector<vector<char> > & board, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==board[row][col] && i!=col) return false;
            if(board[i][col]==board[row][col] && i!=row) return false;
        }

        int subrow=row/3;
        int subcol=col/3;
        for(int i=subrow*3;i<(subrow+1)*3;i++)
        {
            for(int j=subcol*3;j<(subcol+1)*3;j++)
            {
                if(board[i][j]==board[row][col] && (i!=row || j!=col)) return false;
            }
        }
        return true;
    }
};
