class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i]++;
            if (result[i] < 10) {
                return result;
            }
            result[i] = 0;
        }
        if (result[0] == 0) {
            result.push_back(0);
            result[0] = 1;
        }
        return result;
    }

};