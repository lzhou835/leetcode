class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9 || board[0].size()!=9) return false;

        for(int i=0;i<9;i++)
        {
            vector<bool> flag(9,false);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]<'0' || board[i][j]>'9') continue;
                int pos=board[i][j]-'0';
                if(board[i][j]=='0' || flag[pos]) return false;
                flag[pos]=true;
            }
        }

        for(int j=0;j<9;j++)
        {
            vector<bool> flag(9,false);
            for(int i=0;i<9;i++)
            {
                if(board[i][j]<'0' || board[i][j]>'9') continue;
                int pos=board[i][j]-'0';
                if(board[i][j]=='0' || flag[pos]) return false;
                flag[pos]=true;
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                vector<bool> flag(9,false);
                for(int m=i*3;m<(i+1)*3;m++)
                {
                    for(int n=j*3;n<(j+1)*3;n++)
                    {
                        if(board[m][n]<'0' || board[m][n]>'9') continue;
                        int pos=board[m][n]-'0';
                        if(board[m][n]=='0' || flag[pos]) return false;
                        flag[pos]=true;
                    }
                }
            }
        }
        return true;
    }
};

