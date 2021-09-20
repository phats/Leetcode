class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int dong = mat.size();
        int cot = mat[0].size();
        vector<int> result(0);
        vector<vector<int>> cheo(dong + cot + 1, vector<int>(0, 0));
        for (int i = 0; i < dong; i++) {
            for (int j = 0; j < cot; j++) {

                cheo[i + j].push_back(mat[i][j]);
            }
        }
        for (int k = 0; k < dong + cot; k++) {
            if (k % 2 == 0) {
                reverse(cheo[k].begin(), cheo[k].end());
            }
            copy(cheo[k].begin(), cheo[k].end(), back_inserter(result));
        }
        return result;
    }
};