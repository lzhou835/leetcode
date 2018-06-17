class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty() || board[0].empty()) return {};
        int m=board.size(), n=board[0].size(), cnt=0;
        int row=click[0], col=click[1];
        if(board[row][col]=='M'){
            board[row][col]='X';
        }else{
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    int x=row+i, y=col+j;
                    if(x<0 || y<0 || x>=m || y>=n) continue;
                    if(board[x][y]=='M') cnt++;
                }
            }
            
            if(cnt>0){
                board[row][col]='0'+cnt;
            }else{
                board[row][col]='B';
                for(int i=-1;i<2;i++){
                    for(int j=-1;j<2;j++){
                        int x=row+i, y=col+j;
                        if(x<0 || y<0 || x>=m || y>=n) continue;
                        if(board[x][y]=='E'){
                            vector<int> pos({x,y});
                            updateBoard(board, pos);
                        }
                    }
                }
            }
        }
        return board;
    }
};
