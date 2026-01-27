class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }
        r = row; c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }
        return true;
    }
    void solve(int row, int n, vector<vector<string>>& ans,
               vector<string>& board, vector<bool>& colUsed) {

        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!colUsed[col] && isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                colUsed[col] = true;
                solve(row + 1, n, ans, board, colUsed);
                board[row][col] = '.';
                colUsed[col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> colUsed(n, false);

        solve(0, n, ans, board, colUsed);

        return ans;
    }
};
