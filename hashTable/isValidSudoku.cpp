class Solution {
public:
    /* key 3 boxes:
       00 01  02
       10 11  12
       20 21  22 */
    bool isValidSudoku(vector<vector<char>>& board) {
        string char_r="r";
        string char_c="c";
        unordered_map<string, bool> isHave;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != '.') {
                    string inRow = board[i][j]+char_r +to_string(i);
                    string inCol = board[i][j]+char_c +to_string(j);
                    string inBox = board[i][j] + to_string(i/3) + to_string(j/3);
                    auto gotInRow = isHave.find(inRow);
                    auto gotInCol = isHave.find(inCol);
                    auto gotInBox = isHave.find(inBox);
                    if (gotInRow != isHave.end() || gotInCol != isHave.end() || gotInBox != isHave.end()) {
                        return false;
                    }
                    else {

                        //seen in row
                        isHave.insert({ inRow,1 });
                        //seen in col
                        isHave.insert({ inCol,1 });
                        //seen in box
                        isHave.insert({ inBox,1 });
                    }
                }
            }
        }
        return true;
    }
};