class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat){
        vector<int> result;
        bool isUp= 1;
        int numberOfColumns=mat[0].size();
        int numberOfRows=mat.size();
        if (numberOfRows==1) return mat[0];
        int i=0,j=0;
        
        while(result.size() != numberOfColumns*numberOfRows){
            result.push_back(mat[i][j]);
            if (!isUp){
                //if end of diagonal DOWN
                if (j==0 || i==numberOfRows-1) {
                    isUp=1;
                //if touch the bottom row
                    if (i != numberOfRows-1){
                        i++;
                    }
                //if touch the first column
                    else{
                        j++;
                    }
                }
                else{
                    i++;
                    j--;
                }

            }
            else if (isUp){
                //if end of diagonal UP
                if (i==0  || j== numberOfColumns-1) {
                    isUp=0;
                //if touch the top row
                    if(j != numberOfColumns-1){
                        j++;
                    }
                //if touch the last column
                    else{
                        i++;
                    }
                    isUp=0;
                }
                else{
                    i--;
                    j++;
                }
            }
        }

        return result;
    }
};