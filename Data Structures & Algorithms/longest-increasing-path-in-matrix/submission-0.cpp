class Solution {
private:
    int rows, cols;
    vector<vector<int>> memo;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        // Return stored answer if already computed
        if (memo[r][c] != 0) return memo[r][c];

        int maxPath = 1; // Minimum path length for any single cell is 1

        for (auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            // Check boundaries and strict increasing condition
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                maxPath = max(maxPath, 1 + dfs(matrix, nr, nc));
            }
        }

        return memo[r][c] = maxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, 0));

        int maxGlobalPath = 0;

        // Try starting the path from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxGlobalPath = max(maxGlobalPath, dfs(matrix, i, j));
            }
        }

        return maxGlobalPath;
    }
};