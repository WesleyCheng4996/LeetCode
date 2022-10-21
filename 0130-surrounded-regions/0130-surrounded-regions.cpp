class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> iscircle(board.size(), vector<bool>(board[0].size(), 0));
        for(int i = 0; i < board.size(); ++i) {
            if(board[i][0] == 'O') {
                change(board, iscircle, i, 0);
            }
            if(board[i].back() == 'O') {
                change(board, iscircle, i, board[i].size() - 1);
            }
        }
        for(int j = 0; j < board[0].size(); ++j) {
            if(board[0][j] == 'O') {
                change(board, iscircle, 0, j);
            }
            if(board.back()[j] == 'O') {
                change(board, iscircle, board.size() - 1, j);
            }
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'O' && iscircle[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void change(vector<vector<char>>& board, vector<vector<bool>>& iscircle, int i, int j) {
        if(iscircle[i][j] == true || board[i][j] == 'X') {
            return ;
        }
        iscircle[i][j] = true;
        if(i - 1 >= 0) {
            change(board, iscircle, i - 1, j);
        }
        if(i + 1 < board.size()) {
            change(board, iscircle, i + 1, j);
        }
        if(j - 1 >= 0) {
            change(board, iscircle, i, j - 1);
        }
        if(j + 1 < board[0].size()) {
            change(board, iscircle, i, j + 1);
        }
    }
};