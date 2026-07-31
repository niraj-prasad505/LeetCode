class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top < bottom && left < right) {

            vector<int> ring;

            // Extract the current ring
            for (int j = left; j <= right; j++) {
                ring.push_back(grid[top][j]);
            }

            for (int i = top + 1; i <= bottom; i++) {
                ring.push_back(grid[i][right]);
            }

            for (int j = right - 1; j >= left; j--) {
                ring.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i > top; i--) {
                ring.push_back(grid[i][left]);
            }

            // Rotate left
            int rotateBy = k % ring.size();
            rotate(ring.begin(), ring.begin() + rotateBy, ring.end());

            int idx = 0;

            // Write the ring back
            for (int j = left; j <= right; j++) {
                grid[top][j] = ring[idx++];
            }

            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = ring[idx++];
            }

            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = ring[idx++];
            }

            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = ring[idx++];
            }

            // Move to the next layer
            top++;
            bottom--;
            left++;
            right--;
        }

        return grid;
    }
};