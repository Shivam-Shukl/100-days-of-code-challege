
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        // code here
        // N is the number of rows
        // M is the number of columns
        int N = grid.size();
        int M = grid[0].size();
        int Max = -1;
        for (int row = 0; row < N - 2; row++) {
            for (int col = 0; col < M - 2; col++) {
                int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2] +
                          grid[row + 1][col + 1] +
                          grid[row + 2][col] +grid[row + 2][col + 1] + grid[row + 2][col + 2];
                Max = max(sum, Max);
            }
        }
        return Max;
    }
};