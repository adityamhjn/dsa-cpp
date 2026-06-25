class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use a 2D integer array instead of unordered_sets for blazing fast O(1) tracking
        // rows[i][j] means: in row i, has the number j+1 been seen?
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                // Convert char '1'-'9' into an integer index 0-8
                int val = board[r][c] - '1'; 
                int box_index = (r / 3) * 3 + (c / 3);

                // If it already exists in the row, col, or box, the board is invalid
                if (rows[r][val] || cols[c][val] || boxes[box_index][val]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][val] = 1;
                cols[c][val] = 1;
                boxes[box_index][val] = 1;
            }
        }
        return true;
    }
};