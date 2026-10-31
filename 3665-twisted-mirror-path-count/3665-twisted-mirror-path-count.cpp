
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        auto move = [&](int x, int y, int dir, long long ways) {
            while (x < m && y < n && grid[x][y] == 1) {
                if (dir == 0) {
                    // Entered while moving right
                    x++;
                    dir = 1;
                } else {
                    // Entered while moving down
                    y++;
                    dir = 0;
                }
            }

            if (x < m && y < n) {
                dp[x][y] = (dp[x][y] + ways) % MOD;
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                long long ways = dp[i][j];

                // Move right
                move(i, j + 1, 0, ways);

                // Move down
                move(i + 1, j, 1, ways);
            }
        }

        return dp[m - 1][n - 1];
    }
};
