class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> column;
        unordered_map<int, unordered_set<int>> square;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (row[r].count(board[r][c]) > 0) {
                    return false;
                }
                row[r].insert(board[r][c]);
                if (column[c].count(board[r][c]) > 0) {
                    return false;
                }
                column[c].insert(board[r][c]);
                int numSquare = (r/3) * 3 + (c/3);
                if (square[numSquare].count(board[r][c]) > 0) {
                    return false;
                }
                square[numSquare].insert(board[r][c]);
            }
        }
        return true;
    }

    
};
