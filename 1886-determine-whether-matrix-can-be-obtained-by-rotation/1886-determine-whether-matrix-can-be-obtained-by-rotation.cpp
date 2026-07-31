class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {

            if (mat == target) {
                return true;
            }
            for (int i = 0; i < mat.size(); i++) {
                for (int j = i + 1; j < mat[0].size(); j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < mat.size(); i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};