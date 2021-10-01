class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result(0);
        int numberOfRows=matrix.size();
        int numberOfColumns=matrix[0].size();
        if (numberOfColumns==1){
            for (int i=0;i<numberOfRows;i++){
                result.push_back(matrix[i][0]);
            }
            return result;
        }
        
        int i=0;
        while(result.size()!=numberOfColumns*numberOfRows){
            for (int j=0+i;j<numberOfColumns-i;j++){
                result.push_back(matrix[0+i][j]);
            }
            if (result.size()== numberOfRows*numberOfColumns) break;
            for (int k=1+i;k<numberOfRows-i;k++){
                result.push_back(matrix[k][numberOfColumns-1-i]);
            }
            if (result.size()== numberOfRows*numberOfColumns) break;
            for (int n=numberOfColumns-i-2;n>=0+i;n--){
                result.push_back(matrix[numberOfRows-1-i][n]);
            }
            if (result.size()== numberOfRows*numberOfColumns) break;
            for (int m=numberOfRows-2-i;m>=1+i;m--){
                result.push_back(matrix[m][i]);
            }
            i++;
        }
        return result;
    }
};