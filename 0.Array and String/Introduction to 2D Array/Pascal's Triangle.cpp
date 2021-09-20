class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows,vector<int>(0,0));
        result[0].push_back(1);
        if (numRows ==1) return result;
        for (int i=1;i<numRows;i++){
            result[i].push_back(1);
            for (int j=1;j<result[i-1].size();j++){
                result[i].push_back(result[i-1][j-1]+result[i-1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};