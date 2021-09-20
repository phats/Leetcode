class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result(0);
        int dong=matrix.size();
        int cot=matrix[0].size();
        if (cot==1){
            for (int i=0;i<dong;i++){
                result.push_back(matrix[i][0]);
            }
            return result;
        }
        
        int i=0;
        while(result.size()!=dong*cot){
            for (int j=0+i;j<cot-i;j++){
                result.push_back(matrix[0+i][j]);
            }
            if (result.size()== dong*cot) break;
            for (int k=1+i;k<dong-i;k++){
                result.push_back(matrix[k][cot-1-i]);
            }
            if (result.size()== dong*cot) break;
            for (int n=cot-i-2;n>=0+i;n--){
                result.push_back(matrix[dong-1-i][n]);
            }
            if (result.size()== dong*cot) break;
            for (int m=dong-2-i;m>=1+i;m--){
                result.push_back(matrix[m][i]);
            }
            i++;
        }
        return result;
    }
};