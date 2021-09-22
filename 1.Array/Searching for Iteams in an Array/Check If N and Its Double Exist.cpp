class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i=arr.size()-1;i> 0;i--){
            for (int j=0;j<i;j++){
                if (arr[i]==2*arr[j]) return 1;
                if (arr[j]==2*arr[i]) return 1;
            }
        }
        return 0;
    }
};