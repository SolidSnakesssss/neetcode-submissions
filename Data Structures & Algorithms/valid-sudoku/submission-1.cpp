class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int grid_len = 9;

        for (int row = 0; row < 9; row++) {
            std::unordered_set<char> saw;

            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                
                if (saw.count(board[row][col])) {
                    return false;
                }

                saw.insert(board[row][col]);
            }
        }

        for (int col = 0; col < 9; col++) {
            std::unordered_set<char> saw;

            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;
                
                if (saw.count(board[row][col])) {
                    return false;
                }

                saw.insert(board[row][col]);
            }
        }

        for (int grid = 0; grid < 9; grid++) {
            std::unordered_set<char> saw;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (grid/3) * 3 + i;
                    int col = (grid%3) * 3 + j;

                    if (board[row][col] == '.') {
                        continue;
                    }

                    if (saw.count(board[row][col])) {
                        return false;
                    }

                    saw.insert(board[row][col]);
                }
            }
        }

        return true;

        // Solution idea: Check each row, col, then grid
    }
};
