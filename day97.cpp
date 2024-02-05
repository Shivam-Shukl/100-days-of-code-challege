class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        // Create a new board to store the next state
        vector<vector<int>> nextBoard(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveCount = 0;

                // Define the indices of the neighbors
                vector<pair<int, int>> neighbors = {
                    {i-1, j-1}, {i-1, j}, {i-1, j+1},
                    {i, j-1}, {i, j+1},
                    {i+1, j-1}, {i+1, j}, {i+1, j+1}
                };

                // Count live neighbors
                for (auto neighbor : neighbors) {
                    int ni = neighbor.first;
                    int nj = neighbor.second;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 1) {
                        liveCount++;
                    }
                }

                // Apply the rules to the next state
                if (board[i][j] == 1) {
                    if (liveCount < 2 || liveCount > 3) {
                        nextBoard[i][j] = 0;
                    } else {
                        nextBoard[i][j] = 1;
                    }
                } else {
                    if (liveCount == 3) {
                        nextBoard[i][j] = 1;
                    }
                }
            }
        }

        // Copy the next state back to the original board
        board = nextBoard;
    }
};
