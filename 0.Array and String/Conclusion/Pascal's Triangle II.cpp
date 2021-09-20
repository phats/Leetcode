class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        if (rowIndex==0) return result;
        result.push_back(1);
        if (rowIndex==1) return result;
        for (int i=2;i<=rowIndex;i++){
            result.push_back(1);
            for (int j=0;j<i-1;j++){
                result.push_back(result[j]+result[j+1]);
            }
            result.push_back(1);
            result.erase (result.begin(),result.begin()+i);
        }
        return result;
    }
};